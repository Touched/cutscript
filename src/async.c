#include "interpreter.h"
#include "engine/memory.h"

void async_spawn(command_function func, u32 *args) {
	struct async_state *node;

	node = (struct async_state *) malloc(sizeof(struct async_state));
	node->next = interpreter_state->async;
	node->func = func;
	memcpy(node->args, args, sizeof(u32) * INTERPRETER_MAX_PARAMS);
	
	interpreter_state->async = node;
}

bool async_exec_single(struct async_state *node) {
	switch (node->func(node->args)) {
	case COMMAND_BLOCK:	/* FIXME: Block makes no sense for async command */
	case COMMAND_ASYNC:
		return false;
	case COMMAND_FINISHED:
		break;
	case COMMAND_ERROR:
		interpreter_set_state(STATE_ERROR);
		break;
	}

	return true;
}

void async_exec(void) {
	struct async_state *node = interpreter_state->async,
		*prev = NULL,
		*temp = NULL;

	while (node != NULL) {
		if (async_exec_single(node)) {
			/* Delete node */
			if (prev == NULL) {
				interpreter_state->async = node->next;
			} else {
				prev->next = node->next;
			}

			temp = node;
			node = node->next;
			free(temp);
		} else {
			node = node->next;
		}
	}
}
	


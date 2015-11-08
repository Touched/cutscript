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

void async_exec(void) {

}
	


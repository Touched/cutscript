#include "engine/memory.h"
#include "interpreter.h"
#include "commands.h"
#include "async.h"
	
void interpreter_free(void) {
	free(interpreter_state);
	interpreter_state = NULL;
}

void interpreter_init(u8 *script) {
	interpreter_state = (struct interpreter *) malloc_and_clear(sizeof(struct interpreter));
	interpreter_state->program_counter = script;
	interpreter_set_state(STATE_PARSE);
}

void interpreter_set_error(void) {
	interpreter_set_state(STATE_ERROR);
}

void interpreter_run(void) {
	u32 *args = (u32*) &interpreter_state->arguments[0];
	
	switch (interpreter_state->active_cmd->func(args)) {
	case COMMAND_BLOCK:
		break;
	case COMMAND_ASYNC:
		async_spawn(interpreter_state->active_cmd->func, args);
	case COMMAND_FINISHED:
		interpreter_set_state(STATE_PARSE);
		break;
	case COMMAND_ERROR:
		interpreter_set_state(STATE_ERROR);
		break;
	}
}

u32 interpreter_parse_arg(enum argument_type arg_length) {
	u32 output = 0;
	
	switch (arg_length) {
	case ARG_BYTE:
		output = interpreter_state->program_counter[0];
		interpreter_state->program_counter++;
		break;

	case ARG_HWORD:
		output = (interpreter_state->program_counter[0])
			| (interpreter_state->program_counter[1] << 8);

		interpreter_state->program_counter += 2;
		break;

	case ARG_WORD:
		output = (interpreter_state->program_counter[0])
			| (interpreter_state->program_counter[1] << 8)
			| (interpreter_state->program_counter[2] << 16)
			| (interpreter_state->program_counter[3] << 24);

		interpreter_state->program_counter += 4;
		break;
	}

	return output;
}

void interpreter_parse(void) {
	if (!interpreter_state->program_counter) {
		interpreter_set_error();
		return;
	}
	
	u8 index = *interpreter_state->program_counter++;
	u8 argc, i;
	enum argument_type arg_length;

	if (index >= COMMANDS_MAX) {
		interpreter_set_error();
		return;
	}

	interpreter_state->active_cmd = (struct command *) &command_table[index];
	argc = interpreter_state->active_cmd->argc;

	variable_clear_locals();

	for (i = 0; i < INTERPRETER_MAX_PARAMS; i++) {
		if (i < argc) {
			arg_length = interpreter_state->active_cmd->argument_lengths[i];
			interpreter_state->arguments[i] = interpreter_parse_arg(arg_length);
		} else {
			interpreter_state->arguments[i] = 0;
		}
	}
	
	interpreter_set_state(STATE_RUNNING);
	interpreter_run();
	return;
}

void interpreter_stop(void) {
	if (interpreter_state->before_end_hook) {
		interpreter_state->before_end_hook();
	}
		
	interpreter_free();
}

void interpreter_error(void) {
	interpreter_stop();
}

const interpreter_state_func interpreter_states[] = {
	[STATE_STOPPED] = interpreter_stop,
	[STATE_PARSE] = interpreter_parse,
	[STATE_RUNNING] = interpreter_run,
	[STATE_ERROR] = interpreter_error,	
};

void interpreter_set_state(enum interpreter_state state) {
	interpreter_state->state = interpreter_states[state];
}

enum interpreter_state interpreter_get_state(void) {
	u8 states = sizeof(interpreter_states) / sizeof(interpreter_state_func);
	u8 i;

	for (i = 0; i < states; i++) {
		if (interpreter_states[i] == interpreter_state->state) {
			return i;
		}
	}

	return STATE_NONE;
}

void interpreter_iteration(void) {
	if (interpreter_state && interpreter_state->state) {
		async_exec();
		interpreter_state->state();
	}
}

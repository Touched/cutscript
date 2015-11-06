#include "engine/memory.h"
#include "interpreter.h"
#include "commands.h"
	
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
	/* Command returns true when done */
	if (interpreter_state->active_cmd->func((u32*) &interpreter_state->arguments[0])
		&& interpreter_state->state == interpreter_run) {
		interpreter_set_state(STATE_PARSE);
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

	for (i = 0; i < argc; i++) {
		arg_length = interpreter_state->active_cmd->argument_lengths[i];
		interpreter_state->arguments[i] = interpreter_parse_arg(arg_length);
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

void interpreter_set_state(enum interpreter_state state) {
	switch (state) {
	case STATE_STOPPED:
		interpreter_state->state = interpreter_stop;
		break;
	case STATE_PARSE:
		interpreter_state->state = interpreter_parse;
		break;
	case STATE_RUNNING:
		interpreter_state->state = interpreter_run;
		break;
	case STATE_ERROR:
		interpreter_state->state = interpreter_error;
		break;
	}
}

void interpreter_iteration(void) {
	if (interpreter_state && interpreter_state->state) {
		interpreter_state->state();
	}
}

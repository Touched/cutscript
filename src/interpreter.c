#include "engine/memory.h"
#include "interpreter.h"
#include "commands.h"
	
void interpreter_free(void) {
	free(interpreter_state);
}

void interpreter_init(u8 *script) {
	interpreter_state = (struct interpreter *) malloc_and_clear(sizeof(struct interpreter));
	interpreter_state->program_counter = script;
	interpreter_state->state = STATE_PARSE;
}

void interpreter_set_error(void) {
	interpreter_state->state = STATE_ERROR;
}

void interpreter_run(void) {
	/* Command returns true when done */
	if (interpreter_state->active_cmd->func((u32*) &interpreter_state->arguments[0])
		&& interpreter_state->state == STATE_RUNNING) {
		interpreter_state->state = STATE_PARSE;
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
	
	interpreter_state->state = STATE_RUNNING;
	interpreter_run();
	return;
}

void interpreter_iteration(void) {
	switch (interpreter_state->state) {
	case STATE_STOPPED:
		interpreter_free();
		break;
	case STATE_PARSE:
		interpreter_parse();
		break;
	case STATE_RUNNING:
		interpreter_run();
		break;
	case STATE_ERROR:
		break;
	}
}

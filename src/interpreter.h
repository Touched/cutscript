#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "engine/types.h"
#include "commands.h"

#define INTERPRETER_MAX_PARAMS 6

enum argument_type {
	ARG_BYTE,
	ARG_HWORD,
	ARG_WORD
};

typedef bool (command_fuction*)(u32 *);

struct command {
	command_function func;
	u8 argc;
	enum argument_type argument_lengths[INTERPRETER_MAX_PARAMS];
};

enum interpreter_state {
	STATE_STOPPED,
	STATE_PARSE,
	STATE_RUNNING,
	STATE_ERROR
};

struct interpreter {
	u8 *program_counter;
	enum interpreter_state state;
	u32 arguments[INTERPRETER_MAX_PARAMS];
	struct command *active_cmd;
};

extern struct interpreter *interpreter_state;

#endif /* INTERPRETER_H */

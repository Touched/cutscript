#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "engine/types.h"

#define INTERPRETER_MAX_PARAMS 6

enum argument_type {
	ARG_BYTE,
	ARG_HWORD,
	ARG_WORD
};

typedef bool (*command_function)(u32 *);

struct command {
	const command_function func;
	const u8 argc;
	const enum argument_type argument_lengths[INTERPRETER_MAX_PARAMS];
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
	u8 tilemap_space[4][0x1000];
	void (*before_end_hook)(void);
};

extern struct interpreter *interpreter_state;

void interpreter_init(u8 *script);
void interpreter_iteration(void);

#endif /* INTERPRETER_H */

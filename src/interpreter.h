#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "engine/types.h"

#define INTERPRETER_MAX_PARAMS 6
#define INTERPRETER_MAX_LOCAL_VARS 12
#define INTERPRETER_MAX_GLOBAL_VARS 128
#define CUTSCRIPT_RESULT(x) variable_set_global(0, x)
#define CUTSCRIPT_GET_RESULT() variable_get_global(0)

enum argument_type {
	ARG_BYTE,
	ARG_HWORD,
	ARG_WORD
};

enum command_return_value {
	COMMAND_BLOCK,		/* 
				 * Run the command function next frame,
				 * but don't process the next command
				 */

	COMMAND_FINISHED,	/* 
				 * Mark the command as complete, and
				 * do not run it next frame
				 */

	COMMAND_ASYNC,		/* 
				 * Run the command function next frame,
				 * but process the next command
				 */

	COMMAND_ERROR,		/* 
				 * Mark the function as exiting due to
				 * an error.
				 */	
};

typedef enum command_return_value (*command_function)(u32 *);

struct command {
	const command_function func;
	const u8 argc;
	const enum argument_type argument_lengths[INTERPRETER_MAX_PARAMS];
};

enum interpreter_state {
	STATE_NONE,
	STATE_STOPPED,
	STATE_PARSE,
	STATE_RUNNING,
	STATE_ERROR
};

typedef void (*interpreter_state_func)(void);

struct async_state {
	u32 args[INTERPRETER_MAX_PARAMS];
	command_function func;
	struct async_state *next;
};

struct interpreter {
	u8 *program_counter;
	interpreter_state_func state;
	u32 arguments[INTERPRETER_MAX_PARAMS];
	u32 global_vars[INTERPRETER_MAX_GLOBAL_VARS];
	u32 local_vars[INTERPRETER_MAX_LOCAL_VARS];
	struct command *active_cmd;
	u8 tilemap_space[4][0x1000];
	void (*before_end_hook)(void);
	struct async_state *async;
	u16 pal_tag;
};


extern struct interpreter *interpreter_state;

void interpreter_init(u8 *script);
void interpreter_iteration(void);
void interpreter_set_state(enum interpreter_state state);
enum interpreter_state interpreter_get_state(void);

u32 variable_get_local(u8 index);
void variable_set_local(u8 index, u32 value);
u32 variable_get_global(u8 index);
void variable_set_global(u8 index, u32 value);
u32 variable_or_value(u32 index);
void variable_clear_locals(void);

#endif /* INTERPRETER_H */

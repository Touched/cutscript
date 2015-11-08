#include "../engine/types.h"
#include "../interpreter.h"

enum command_return_value command_goto(u32 *args) {
	interpreter_state->program_counter = (u8 *) args[0];
	return COMMAND_FINISHED;
}

enum command_return_value command_end(u32 *args) {
	interpreter_set_state(STATE_STOPPED);
	return COMMAND_FINISHED;
}

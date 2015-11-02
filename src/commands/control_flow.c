#include "../engine/types.h"
#include "../interpreter.h"

bool command_goto(u32 *args) {
	interpreter_state->program_counter = (u8 *) args[0];
	return true;
}

bool command_end(u32 *args) {
	interpreter_state->state = STATE_STOPPED;
	return true;
}

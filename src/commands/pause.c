#include "../engine/types.h"
#include "../interpreter.h"

enum command_return_value command_pause(u32 *args) {
	if (args[0]--) {
		return COMMAND_FINISHED;
	} else {
		return COMMAND_BLOCK;
	}
}


#include "../engine/types.h"
#include "../interpreter.h"

enum command_return_value command_nop(u32 *args) {
	return COMMAND_FINISHED;
}

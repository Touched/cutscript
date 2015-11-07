#include "../engine/types.h"

bool command_pause(u32 *args) {
	return !(args[0]--);
}


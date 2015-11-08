#include "../engine/video.h"
#include "../interpreter.h"

enum command_return_value command_pal_fade(u32 *args) {
	s8 speed = args[0];
	u8 from = args[1];
	u8 to = args[2];
	u16 color = args[3];
	
	fade_screen(0xFFFFFFFF, speed, from, to, color);

	return COMMAND_FINISHED;
}

enum command_return_value command_pal_load(u32 *args) {
	u8 *palette = (u8 *) args[0];
	u16 offset = (u16) args[1];
	u16 size = (u16) args[2];
	
	gpu_pal_apply(palette, offset, size);

	return COMMAND_FINISHED;
}

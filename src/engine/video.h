#ifndef ENGINE_VIDEO_H
#define ENGINE_VIDEO_H

#include "types.h"

struct fade_ctrl {
	u16 bg_pal_bitfield;
	u16 obj_pal_bitfield;
	u16 scale;
	u16 mix_color;
	u8 field_8;
	u8 field_9;
	u8 field_A;
	u8 field_B;	
};

struct fade_ctrl pal_fade_control;

bool fade_screen(u32 bitmask, s8 speed, u8 to, u8 from, u16 color);

#endif /* ENGINE_VIDEO_H */

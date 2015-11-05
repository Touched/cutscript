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
void lcd_io_set(u8, u16);
void vblank_hander_set(void (*)(void));
void vblank_hander_callback(void);
void gpu_tile_bg_drop_all_sets(u8);
void bg_positions_reset(void);
void callback_clear_and_init(void);
void bgid_nullify_tilemap(u8);
void textbox_something(void);
void objc_exec(void);
void obj_sync_something(void);
void fade_and_return_progress_probably(void);

#endif /* ENGINE_VIDEO_H */

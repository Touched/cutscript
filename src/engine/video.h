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
void pal_set_something(u8, u8, u8, u8, u8);
void overworld_free_bgmaps(void);
void lcd_io_set(u8, u8);
void vblank_hander_set(void (*)(void));
void vblank_hander_callback(void);
void gpu_tile_bg_drop_all_sets(u8);
void bg_positions_reset(void);
void reset_and_init_alot(void);
void bgid_nullify_tilemap(u8);
void mapldr_continue_scripts_restart_music(void);
void help_system_enable_unless_flashback__sp199(void);

#endif /* ENGINE_VIDEO_H */

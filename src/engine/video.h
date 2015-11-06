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

struct bg_config {
	u8 active : 1;
	u8 padding : 1;
	u8 screen_size : 2;
	u8 priority : 2;
	u8 mosaic : 1;
	u8 wraparound : 1;
	u8 character_base : 2;
	u8 screen_base : 5;
	u8 palette : 1; 	/* 1: 256/1, 0: 16/16 */
	u16 unknown;
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
u16 gpu_copy_to_tileset(u8 layer, u8 *tiles, u16 size, u16 offset);
void gpu_copy_tilemap(u8 layer, u8 *map, u16 size_or_null, u16 offset);
void gpu_pal_apply(u8 *palette, u16 offset, u16 size);
void bgid_send_tilemap(u8 layer);
void bgid_set_tilemap(u8 layer, u8 *space);
void bg_vram_setup(u8 layer, struct bg_config *config, u8 layers);

#endif /* ENGINE_VIDEO_H */

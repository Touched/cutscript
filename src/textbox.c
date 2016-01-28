#include "types.h"
#include "textbox.h"


/* TODO: Make cutscript functions which use these */

void textbox_set_text(u8 *string, u8 font, u8 text_bg, u8 text_colour, u8 shadow, u8 text_bg_box) {
	textflags.unknown[0] = textflags.unknown[0] | 1;
	if (text_bg_box) {
		rboxid_clear_pixels(0, 0xFF); // transparent
	} else {
		rboxid_clear_pixels(0, 0x11); // white
	}
	rboxid_08003FA0(0);
	rboxid_to_vram(0, 0);
	box_related_one(0, font, string, sav2_get_text_speed(), 0, text_colour, text_bg, shadow);
}

void create_battle_box() {
	// this is for the textbox that comes up during battle
	sub_0800F34C();
	lz77_uncomp_vram((void *)0x8D00000, (void *)0x6000000);
	sub_080F696C(0, 0x8D00000, 0, 0, 0);
	sub_08002040(0, 0x8D0051C, 0, 0);
	bgid_send_tilemap(0);
	pal_decompress_slice_to_faded_and_unfaded((void *)0x8D004D8, 0, 0x40);
}

void create_curved_box() {
	// this is for the standard textbox in scripts
	box_curved(0, 1);
}

void display_textbox() {
	gpu_sync_bg_show(0);
}

void quick_setup_textbox(u8 string_id) {
	create_battle_box();
	display_textbox();
	//textbox_set_text((u8 *)0x81C55C9, 1, 0, 1, 3, 1);
	textbox_set_text(battle_strings.string[string_id], 1, 0, 1, 3);
}











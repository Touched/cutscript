#include "../interpreter.h"
#include "../engine/types.h"
#include "../engine/video.h"
#include "../engine/memory.h"

bool command_bg_load(u32 *args) {
	u8 layer = (u8) args[0];
	u8 *tileset = (u8*) args[1];
	u8 *tilemap = (u8*) args[2];

	decompress_with_fallback_maybe(layer, tileset, 0, 0, 0);
	gpu_copy_tilemap(layer, tilemap, 0, 0);
	bgid_send_tilemap(layer);

	return true;
}

bool command_BG_display(arg_1){
	/* display a BG */
	return true;
}

bool command_BG_move(arg_1, arg_2, arg_3){
	/* set a BG's coords by ID */
	return true;
}

bool command_BG_del(arg_1){
	/* delete a BG by ID*/
	return true;
}

bool command_BG_translate(arg_1, arg_2, arg_3, arg_4){
	/* translate a BG by ID to location at speed */
	return true;
}

bool command_BG_pal_update(arg_1, arg_2){
	/* update a BG's pal */
	return true;
}

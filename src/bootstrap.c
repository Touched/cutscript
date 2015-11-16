#include "engine/memory.h"
#include "engine/video.h"
#include "engine/overworld.h"
#include "engine/callback.h"
#include "interpreter.h"

void callback_cutscript_run(void) {
	task_exec();
	textbox_something();
	objc_exec();
	obj_sync_something();
	fade_and_return_progress_probably();

	interpreter_iteration();
}

const struct bg_config config[4] = {
	{0, 0, 0, 3, 1, 1, 1, 4},
	{1, 0, 1, 2, 1, 1, 1, 8},
	{0, 1, 2, 1, 0, 1, 1, 16},
	{1, 1, 3, 0, 1, 1, 1, 24}	
};

void hook_return_to_overworld(void) {
	set_callback2(c2_exit_to_overworld_2_switch);
}

void vblank_handler_callback(void) {
	gpu_sprites_upload();
	copy_queue_process();
	gpu_pal_upload();
}

void callback_bootstrap(void) {
	u8 i;
	
	/* Clean up and setup */
	lcd_io_set(0, 0);
	vblank_hander_set(vblank_handler_callback);
	gpu_tile_bg_drop_all_sets(0);
	bg_positions_reset();
	callback_clear_and_init();

	lcd_io_set(0, 0x1040);

	bg_vram_setup(0, (struct bg_config *) config, 4);

	for (i = 0; i < 4; i++) {
		bgid_set_tilemap(i, interpreter_state->tilemap_space[i]);
	}
	
	/* Allow cutscript to return to the overworld when done */
	interpreter_state->before_end_hook = hook_return_to_overworld;

	/* Run the interpreter and callbacks  */
	callback_cutscript_run();
	set_callback2(callback_cutscript_run);
}

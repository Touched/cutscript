#include "engine/memory.h"
#include "engine/video.h"
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
	{1},
	{1},
	{1},
	{1}	
};

void callback_bootstrap(void) {
	u8 i;
	
	/* Clean up and setup */
	lcd_io_set(0, 0);
	vblank_hander_set(vblank_hander_callback);
	gpu_tile_bg_drop_all_sets(0);
	bg_positions_reset();
	callback_clear_and_init();

	lcd_io_set(0, 0x1040);

	for (i = 0; i < 4; i++) {
		bgid_set_tilemap(i, interpreter_state->tilemap_space[i]);
	}
	
	bg_vram_setup(0, (struct bg_config *) config, 4);	

	/* Run the interpreter and callbacks  */
	callback_cutscript_run();
	set_callback2(callback_cutscript_run);
}

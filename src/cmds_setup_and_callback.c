#include "engine/memory.h"
#include setup_preparation.h

void set_up(void) {
	script_env_2_enable();
	help_system_disable_sp198();
	pal_set_something(-1, 0, 0, 0x10, 0); // should wait for completion?
	overworld_free_bgmaps(); // free BGs and rboxes
	
	// do unknown magic - interrupt, so stop drawing to screen maybe?
	lcd_io_set(0, 0);
	
	vblank_hander_set (&vblank_hander_callback);
	bg_positions_reset();
	
	/* obj reset, pal_fade_ctrl_and_dead_struct_reset, gpu pal alloc reset
	tasks init, dp12 abort */
	reset_and_init_alot();
}
	
	
void map_reload(void) {
	bgid_nullify_tilemap(0);
	bgid_nullify_tilemap(1);
	bgid_nullify_tilemap(2);
	bgid_nullify_tilemap(3);
	*maphook = (&mapldr_continue_scripts_restart_music);
	help_system_enable_unless_flashback__sp199();
}

	

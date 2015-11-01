#include "engine/memory.h"
#include setup_preparation.h

/* To move to BPRE.ld file */
script_env_2_enable = 0x08069940|1;
help_system_disable_sp198 = 0x0812B478|1;
pal_set_something = 0x08070588|1;
overworld_free_bgmaps = 0x080563F0|1;
lcd_io_set = 0x08000A38|1;
vblank_hander_set = 0x080006F4|1;
vblank_hander_callback = 0x08046FC0|1;
gpu_tile_bg_drop_all_sets = 0x08001618|1;
bg_positions_reset = 0x0812D594|1;
reset_and_init_alot = 0x080F4E24|1;


void set_up(void) {
	script_env_2_enable();
	help_system_disable_sp198();
	pal_set_something(-1, 0, 0, 0x10, 0); // should wait for completion?
	overworld_free_bgmaps(); // free BGs and rboxes
	
	// do unknown magic
	lcd_io_set(0, 0);
	
	vblank_hander_set (&vblank_hander_callback);
	bg_positions_reset();
	
	/* obj reset, pal_fade_ctrl_and_dead_struct_reset, gpu pal alloc reset
	tasks init, dp12 abort */
	reset_and_init_alot();
}
	
	
void map_reload(void) {
	*maphook = (&mapldr_continue_scripts_restart_music);
}

	

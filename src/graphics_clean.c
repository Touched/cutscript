#include "./engine/memory.h"
#include "./engine/setup.h"

void set_up(void) {
	script_env_2_enable();
	help_system_disable_sp198();
	pal_set_something(-1, 0, 0, 0x10, 0); // todo: wait
	overworld_free_bgmaps(); // frees rboxes too
	lcd_io_set(0, 0);
	vblank_hander_set (&vblank_hander_callback);
	bg_positions_reset();
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

	

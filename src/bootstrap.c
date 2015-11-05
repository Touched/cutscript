#include "./engine/memory.h"
#include "./engine/video.h"

void callback_bootstrap(void) {
	/* Clean up */
	lcd_io_set(0, 0);
	vblank_hander_set(vblank_hander_callback);
	gpu_tile_bg_drop_all_sets(0);
	bg_positions_reset();
	callback_clear_and_init();
}

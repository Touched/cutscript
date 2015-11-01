/* Functions and mem addr for cutscene preparation */

void script_env_2_enable(void);	
void help_system_disable_sp198(void);
void pal_set_something(u8, u8, u8, u8, u8);
void overworld_free_bgmaps(void);
void lcd_io_set(u8, u8);
void vblank_hander_set(void (*callback)(u8));
void vblank_hander_callback(void);
void gpu_tile_bg_drop_all_sets(u8);
void bg_positions_reset(void);
void reset_and_init_alot(void);
u32 *maphook = (u32*)0x3005020;
void mapldr_continue_scripts_restart_music(void);
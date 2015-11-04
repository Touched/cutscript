/*
 * Data
 */

script_env_1 = 0x03000EB0;
script_env_2 = 0x03000F28;
pal_fade_control = 0x02037AB8;
map_post_load_hook = 0x03005020;

/*
 * Functions
 */

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
help_system_enable_unless_flashback__sp199 = 0x0812B484|1;
bgid_nullify_tilemap = 0x08001FD4|1;
mapldr_continue_scripts_restart_music = 0x0807DD24|1;

load_var_value = 0x0806E568|1;
var_set_value = 0x0806E584|1;
var_get_pointer = 0x0806E454|1;
mem_copy = 0x081E5E78|1;
malloc = 0x08002B9C|1;
malloc_and_clear = 0x08002BB0|1;
free = 0x08002BC4|1;
script_env_2_enable = 0x08069940|1;
task_add = 0x0807741C|1;
task_del = 0x08077508|1;
set_callback2 = 0x08000544|1;
set_callback1 = 0x080565E0|1;
fade_screen = 0x08070588|1;
sp198_help_system_disable = 0x0812B478|1;
overworld_free_bgmaps = 0x080563F0|1;
mapldr_continue_scripts_restart_music = 0x0807DD24|1;

/*
 * Custom Data
 */

interpreter_state = 0x02036E30;

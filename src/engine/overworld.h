#ifndef ENGINE_OVERWORLD_H
#define ENGINE_OVERWORLD_H

void mapldr_continue_scripts_restart_music(void);

void c2_exit_to_overworld_2_switch(void);

void overworld_free_bgmaps(void);

extern void (*map_post_load_hook)(void);

#endif /* ENGINE_OVERWORLD_H */

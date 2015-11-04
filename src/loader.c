#include "interpreter.h"
#include "engine/script.h"
#include "engine/callback.h"
#include "engine/video.h"

void task_load_cutscript(u8 task_id) {

}

void ow_script_cutscript_special(void) {
	struct script_env *env = NULL;

	/* Select active script environment */
	if (script_env_1.mode) {
		env = &script_env_1;
	} else if (script_env_2.mode) {
		env = &script_env_2;
	}

	if (env) {
		/* 
		 * Get the pointer to the cutscript script from 
		 * overworld script bank 1
		 */
		interpreter_init((u8 *) env->vars[1]);

		/* Copy egg hatching special */
		script_env_2_enable();
		task_add(task_load_cutscript, 0xA);
		fade_screen(0xFFFFFFFF, 0, 0, 0x10, 0);
		sp198_help_system_disable();
	}
}

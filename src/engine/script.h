#ifndef ENGINE_SCRIPT_H
#define ENGINE_SCRIPT_H

#include "types.h"

struct script_env {
	u8 depth;
	u8 mode;
	u8 cmp_result;
	u8 field_3;
	u32 pointer_asm;
	u32 pointer_script;
	u32 stack[20];
	u32 cmd_table;
	u32 cmd_table_max;
	u32 vars[4];
	u8 enabled;
	u8 field_75;
	u8 keypad_control_enabled;
	u8 keypad_override_direction;
};

extern struct script_env script_env_1;
extern struct script_env script_env_2;

void script_env_2_enable(void);
void sp198_help_system_disable(void);

#endif /* ENGINE_SCRIPT_H */
	

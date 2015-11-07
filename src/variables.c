#include "interpreter.h"
	
u32 variable_get_local(u8 index) {
	if (index < INTERPRETER_MAX_LOCAL_VARS) {
		return interpreter_state->local_vars[index];
	} else {
		return 0;
	}
}

void variable_set_local(u8 index, u32 value) {
	if (index < INTERPRETER_MAX_LOCAL_VARS) {
		interpreter_state->local_vars[index] = value;
	}
}

u32 variable_get_global(u8 index) {
	if (index < INTERPRETER_MAX_GLOBAL_VARS) {
		return interpreter_state->global_vars[index];
	} else {
		return 0;
	}
}

void variable_set_global(u8 index, u32 value) {
	if (index < INTERPRETER_MAX_GLOBAL_VARS) {
		interpreter_state->global_vars[index] = value;
	}
}

u32 variable_or_value(u32 index) {
	if (index < INTERPRETER_MAX_GLOBAL_VARS) {
		return interpreter_state->global_vars[index];
	} else {
		return index;
	}
}

void variable_clear_locals(void) {
	u8 i;
	for (i = 0; i < INTERPRETER_MAX_LOCAL_VARS; i++) {
		interpreter_state->local_vars[i] = 0;
	}
}

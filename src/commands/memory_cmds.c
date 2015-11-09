#include "../engine/memory_cmds.h"
#include "../interpreter.h"
#include "../engine/types.h"

extern void interpreter_set_error(void);

bool command_ow_var_load(u32 *args){
	u16 var = (u16) args[0]; 
	u32 *var_index = (u32 *) args[1];
	if (var < 0x3FFF) {
		interpreter_set_error();
		return true;
	}
	*var_index = (u32) load_var_value(var); 
	return true;
}
	

bool command_ow_var_set(u32 *args){
	u16 var = (u16) args[0];
	u8 value = (u8) args[1];
	u8 status = var_set_value(var, value);
	if (status < 1){
		interpreter_set_error();
	}
	return true;
}


bool command_ow_var_access(u32 *args){
	u16 var = (u16) args[0];
	u32 *var_index = (u32 *)args[1];
	*var_index = (u32) var_get_pointer(var);
	if (*var_index == 0){
		interpreter_set_error();
	}
	return true;
}

/* Low level commands */

/*
bool command_value_set(u32 arg_1, u32 arg_2, u32 arg_3){
	u32 *source = (u32 *)arg_1;
	u32 size = arg_2;
	u32 *destination = (u32 *)arg_3;
	if ((*destination + size) < 0x08000000){
		local_var.status = 1;
		mem_copy(*destination, *source, size); 
	} else {
		interpreter_set_error();
	}
	return true;
}


bool command_mem_malloc(u32 arg_1, u32 arg_2){
	u32 size = arg_2;
	u32 *destination = (u32 *)arg_1;
	destination = malloc(size);
	if (*destination < 1){
		interpreter_set_error();
	}
	return true;
}


bool command_malloc_free(u32 arg_1){
	u32 *source = (u32 *)arg_1;
	free(source);
	// should check src in dyn mem area. TODO.
	return true;
}
*/

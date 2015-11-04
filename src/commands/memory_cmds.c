#include "../engine/memory_cmds.h"
#include "../interpreter.h"
#include "../engine/types.h"

/* local_var.status = 0 if fail, and 1 if success. True is returned for the
engine to continue onto the next command */


bool ow_var_load(u32 arg_1, u32 arg_2){
	u16 var = (u16) arg_1; 
	u32 *var_index = (u32 *) arg_2;
	if (var < 0x3FFF) {
		local_var.status = 0;
	} else {
		local_var.status = 1;
		*var_index = (u32) load_var_value(var); 
	}
	return true;
}
	

bool ow_var_set(u32 arg_1, u32 arg_2){
	u16 var = (u16) arg_1;
	u8 value = arg_2;
	local_var.status = var_set_value(var, value);
	return true;
}


bool ow_var_access(u32 arg_1, u32 arg_2){
	u16 var = (u16) arg_1;
	u32 *var_index = (u32 *)arg_2;
	*var_index = (u32) var_get_pointer(var);
	if (*var_index == 0){
		local_var.status = 0;
	} else {
		local_var.status = 1;
	}
	return true;
}


bool value_set(u32 arg_1, u32 arg_2, u32 arg_3){
	u32 *source = (u32 *)arg_1;
	u32 size = arg_2;
	u32 *destination = (u32 *)arg_3;
	if ((*destination + size) < 0x08000000){
		local_var.status = 1;
		mem_copy(*destination, *source, size); 
	} else {
		local_var.status = 0;
	}
	return true;
}


bool mem_malloc(u32 arg_1, u32 arg_2){
	u32 size = arg_2;
	u32 *destination = (u32 *)arg_1;
	destination = malloc(size);
	if (*destination != 0){
		local_var.status = 1;
	} else {
		local_var.status = 0;
	}
	return true;
}


bool malloc_free(u32 arg_1){
	u32 *source = (u32 *)arg_1;
	free(source);
	local_var.status = 1; // should check src in dyn mem area. TODO.
	return true;
}

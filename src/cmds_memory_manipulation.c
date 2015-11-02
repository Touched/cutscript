#include "engine/memory.h"
#include "interpreter.h"
#include "general_command_resources.h"
#include "memory_functions.h"

/* local_var.status = 0 if fail, and 1 if success. True is returned for the
engine to continue onto the next command */


enum bool var_load(u16 var, u32 *var_index){
	if (var < 0x3FFF) {
		local_var.status = 0;
	} else {
		local_var.status = 1;
		*var_index = (u32) load_var_value(var); 
	}
	return TRUE;
}
	

enum bool var_set(u16 var, u8 value){
	local_var.status = var_set_value(value);
	return TRUE;
}


enum bool var_access(u16 var, u32 *var_index){
	*var_index = (u32) var_get_pointer(var);
	if (*var_index == 0){
		local_var.status = 0;
	} else {
		local_var.status = 1;
	}
	return TRUE;
}


enum bool value_set(u32 *source, u32 size, u32 *destination){
	if ((*destination + size) < 0x08000000){
		local_var.status = 1;
		mem_copy(*destination, *source, size); 
	} else {
		local_var.status = 0;
	}
	return TRUE;
}


enum bool mem_malloc(u32 *destination, u32 size){
	destination = malloc(size);
	if (*destination != 0){
		local_var.status = 1;
	} else {
		local_var.status = 0;
	}
	return TRUE;
}


enum bool malloc_free(u32 *source){
	free(source);
	local_var.status = 1; // should check src in dyn mem area. TODO.
	return TRUE;
}

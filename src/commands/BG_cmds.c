#include "../interpreter.h"
#include "../engine/types.h"

bool command_BG_load(arg_1, arg_2, arg_3, arg_4){
	/* load a BG */
	return true;
}

bool command_BG_display(arg_1){
	/* display a BG */
	return true;
}

bool command_BG_move(arg_1, arg_2, arg_3){
	/* set a BG's coords by ID */
	return true;
}

bool command_BG_del(arg_1){
	/* delete a BG by ID*/
	return true;
}

bool command_BG_translate(arg_1, arg_2, arg_3, arg_4){
	/* translate a BG by ID to location at speed */
	return true;
}

bool command_BG_pal_update(arg_1, arg_2){
	/* update a BG's pal */
	return true;
}

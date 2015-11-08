#include "../interpreter.h"
#include "../engine/types.h"

enum command_return_value command_create_oam(arg_1, arg_2, arg_3){
	/* create a struct using args */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_display(arg_1){
	/* display OAM */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_move(arg_1, arg_2, arg_3){
	/*set new x/y position*/
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_del(arg_1){
	/* delete oam */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_translate(arg_1){
	/* translte an OAM to a position*/
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_pal_update(arg_1, arg_2){
	/* change pal of an OAM */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_rotate(arg_1, arg_2){
	/* rotate OAM a direction */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_flip(arg_1, arg_2){
	/* flip an oam a certain axis */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_zoom(arg_1, arg_2, arg_3){
	/* Zoom into part of an OAM */
	return COMMAND_FINISHED;
}

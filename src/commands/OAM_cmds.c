#include "../interpreter.h"
#include "../engine/types.h"
#include "../engine/objects.h"
#include "../engine/memory.h"

void build_template (struct objtemplate objtemp, u32 *image) {
	objtemp.tiles_tag = interpreter_state->obj_ids->size;
	objtemp.pal_tag = interpreter_state->obj_ids->size;
	objtemp.oam = poke_oam_battle;
	objtemp.animation = anim_poke;
	objtemp.graphics->graphics = (u8 *)(image);
	objtemp.graphics->size = (u32)(*(image +1));
	objtemp.rotscale = rotscale_empty;
	objtemp.callback = oac_nullsub; 
}


enum command_return_value command_create_oam(u32 *args) {
	struct objtemplate *objtemp = (struct objtemplate *) malloc(sizeof(struct objtemplate));
	build_template(*objtemp, (u32 *)args[0]);
	interpreter_state->obj_ids->obj_used[interpreter_state->obj_ids->size] =
	template_instanciate_forward_search(objtemp, args[1], args[2], args[3]);
	
	interpreter_state->obj_ids->tail = 
	interpreter_state->obj_ids->obj_used[interpreter_state->obj_ids->size];
	
	interpreter_state->obj_ids->size ++;
	return COMMAND_FINISHED;
}



enum command_return_value command_oam_move(u32 *args) {
	/*set new x/y position*/
	objects[interpreter_state->obj_ids->obj_used[args[0]]].x = args[1];
	objects[interpreter_state->obj_ids->obj_used[args[0]]].y = args[2];
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_display(u32 *args) {
	/* show oam - redundant? */
	u8 index = (u8) args[0];
	u8 i = 0;
	while (i < 40){
		u8 current_id = *(obj_ids_to_display + i);
		if (current_id == 0x3F){
			*(obj_ids_to_display + i) = index;
			return COMMAND_FINISHED;
		}
	}
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_del(u32 *args) {
	/* delete oam */
	u8 index = (u8) args[0];
	obj_delete(&objects[index]);
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_translate(arg_1) {
	/* translate an OAM to a position*/
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_pal_update(arg_1, arg_2) {
	/* change pal of an OAM */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_rotate(arg_1, arg_2) {
	/* rotate OAM a direction */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_flip(arg_1, arg_2) {
	/* flip an oam a certain axis */
	return COMMAND_FINISHED;
}

enum command_return_value command_oam_zoom(arg_1, arg_2, arg_3) {
	/* Zoom into part of an OAM */
	return COMMAND_FINISHED;
}

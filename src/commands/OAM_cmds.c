#include "../interpreter.h"
#include "../engine/types.h"
#include "../engine/callback.h"
#include "../engine/objects.h"

void build_default_objtemplate(void){
	objtemplate.tiles_tag ++;
	objtemplate.pal_tag ++;

	// OAM struct build 
	objtemplate.OAM.y = 0x0;
	objtemplate.OAM.flags1 = 0x1;
	objtemplate.OAM.x = 0x0;
	objtemplate.OAM.msb_of_x_and_flags2 = 0xC0;
	objtemplate.OAM.attr2 = 0x0;
	objtemplate.OAM.rotscaleinfo = 0x0;
	
	objtemplate.image_anims = (u32 *)0x082349BC;
	objtemplate.rot_scale_anims = (u32 *)0x8231CFC;
	objtemplate.callback = (u32 *)0x810BB88|1;	
}

bool command_create_oam(u32 *args){
	/* create an OAM using args */
	build_default_objtemplate();
	
	// args[0] x, args[1] y, args[2] mystery. 0 by default
	interpreter.active_obj_ids[interpreter.active_obj_ids.size] = 
	template_instanciate_forward_search(objtemplate, (u16) args[0], (u16) args[1], (u8) args[2]);
	
	interpreter.active_obj_ids.tail_obj = 
	interpreter.active_obj_ids[interpreter.active_obj_ids.size]
	
	
	interpreter.active_obj_ids.size ++;
	return true;
}

bool command_oam_del(u32 *args){
	object_del((u8) args[0]);
	return true;
}

void oam_move(u8 id, u16 x, u16 y){
	objects[id].pos_1_x = x;
	objects[id].pos_1_y = y;
	return;
}



// Task system based OAM transition

bool oam_move_task(u8 task_id){
	u8 speed = tasks[task_id].priv[3];
	if ((objects[tasks[task_id].priv[0]].pos_1_x + speed) > tasks[task_id].priv[1]){
		objects[tasks[task_id].priv[0]].pos_1_x + speed;
	} else {
		task_del(task_id);
		return;
	}
	if ((objects[tasks[task_id].priv[0]].pos_1_y + speed) > tasks[task_id].priv[2]){
		objects[tasks[task_id].priv[0]].pos_1_y + speed;
	} else {
		task_del(task_id);
		return;
	}
	return;
}

bool command_oam_translate_synced(u32 *args){

	u8 task_id = task_add(oam_move);
	tasks[task_id].priv[0] = (u16) args[0]; // ID
	tasks[task_id].priv[1] = (u16) args[1]; // X 
	tasks[task_id].priv[2] = (u16) args[2]; // Y
	tasks[task_id].priv[3] = (u16) args[3]; // Speed
	return true;
} 

/* non task version, relying on interpreter state for frame by frame */
bool command_oam_translate(u32 *args){
	if ((objects[arg[0]].pos_1_x + arg[3]) > arg[1]){
		objects[arg[0]].pos_1_x + arg[3];
	} else {
		return true;
	}
	if ((objects[arg[0]].pos_1_y + arg[3]) > arg[2]){
		objects[arg[0]].pos_1_y + arg[3];
	} else {
		return true;
	}
	return false;
}

bool command_oam_move(u32 *args){
	/* fast set new X/Y pos */
	oam_move(arg[0], arg[1], arg[2]);
	return true;
}

bool command_oam_pal_update(arg_1, arg_2){
	/* change pal of an OAM */
	return true;
}

bool command_oam_rotate(arg_1, arg_2){
	/* rotate OAM a direction */
	return true;
}

bool command_oam_flip(arg_1, arg_2){
	/* flip an oam a certain axis */
	return true;
}

bool command_oam_zoom(arg_1, arg_2, arg_3){
	/* Zoom into part of an OAM */
	return true;
}
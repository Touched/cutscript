#include "../engine/buttons.h"
#include "../engine/types.h"

bool command_waitbutton(u32 *args) {
	switch (superstate.buttons_new_remapped){
	case 0:
		return false;
	default:
		return true;
	};
}

bool command_waitbutton_specific(u32 *args) {
	switch (superstate.buttons_new_remapped){
	case (u16 args[0]):
		return true;
	default:
		return false;
	};
	
}

bool command_read_button(u32 *args) {
	interpreter.localvar[args[0]] = (u32) superstate.buttons_new_remapped;
	return true;
}

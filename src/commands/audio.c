#include "../interpreter.h"

enum command_return_value command_play_song(u32 *args) {
	void audio_play(u8);
	audio_play((u8) args[0]);
	return COMMAND_FINISHED;
}

enum command_return_value command_check_audio(u32 *args) {
	u8 check_audio(void);
	CUTSCRIPT_RESULT(check_audio());
	return COMMAND_FINISHED;
}

enum command_return_value command_play_map_song(u32 *args) {
	void current_map_music_set(u8);
	current_map_music_set((u8) args[0]);
	return COMMAND_FINISHED;
}


enum command_return_value command_fanfare(u32 *args) {
	void fanfare(u8);
	u8 fanfare_wait(void);
	
	if (CUTSCRIPT_GET_RESULT > 0) {
		u8 status = fanfare_wait();
		if (status == 1) {
			return COMMAND_BLOCK;
		} else {
			return COMMAND_FINISHED;
		}
	} else {
		CUTSCRIPT_RESULT(1);
		fanfare((u8) args[0]);
		COMMAND_BLOCK;
	}
}

enum command_return_value command_play_cry(u32 *args) {
	void cry_related(u16, u8);
	cry_related((u16) args[0], 0);
	return COMMAND_FINISHED;
}

struct superstate {
	u32 *callback1;
	u32 *callback2;
	u32 *callback2backup;
	u32 *callback5_vblank;
	u32 *hblank_callback;
	u32 *field_14;
	u32 *field_18;
	u32 bits_to_wait_for;
	u32 *ptr_vblank_counter;
	u32 field_24;
	u16 buttons_held;
	u16 buttons_new;
	u16 buttons_held_remapped;
	u16 buttons_new_remapped;
	u16 nuttons_new_and_keyrepeat;
	u16 keypad_countdown;
	u32 unused;
	struct sprite sprites[128]
	u8 multi_purpose_state_tracker;
	u8 gpu_sprites_upload_skip;
};

struct sprite {
	u8 y;
	u8 flag1;
	u8 x;
	u8 msb_of_x_and_flags2;
	u16 attr2;
	u16 rotscaleinfo;
};

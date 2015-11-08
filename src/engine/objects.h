struct objtemplate {
	u16 tiles_tag;
	u16 pal_tag;
	struct OAM;
	u32 *image_anims;
	u32 *gfx_table;
	u32 *rot_scale_anims;
	u32 *callback;
};

struct OAM {
	u8 y;
	u8 flags1;
	u8 x;
	u8 msb_of_x_and_flags2;
	u16 attr2;
	u16 rotscaleinfo;
};

struct objects {
	struct obj[0x3F];
};

struct obj {
	struct final_oam;
	u32 *animation_table;
	u32 *gfc_table;
	u32 *rotscale_table;
	u32 *template;
	u32 *callback;
	u16 pos_1_x;
	u16 pos_2_y;
	u32 pos_2;
	u16 pos_neg_center;
	u8 anim_number;
	u8 anim_frame;
	u8 anim_delay_countdown;
	u8 anim_unknown_counter;
	u8 private[8];
	u8 bitfield2;
	u8 bitfield;
	u8 anim_data_offset;
	u8 field_42;
	u8 y_height_related;
};
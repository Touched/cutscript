#ifndef TEXTBOX_RELATED_H
#define TEXTBOX_RELATED_H

struct strings_to_display {
	u8 *string[50]; // I have it as 50 now. Strings need to be ROM pointers
};

struct textflags {
	u8 unknown[4];
};

void box_related_one(u8, u8, u8* string, u8, u8, u8, u8, u8);
void rboxid_to_vram(u8, u8);
void box_curved(u8, u8);
void sub_080F696C(u8, u32, u8, u8, u8);
void sub_08002040(u8, u32, u8, u8);
void gpu_sync_bg_show(u8);
void bgid_send_tilemap(u8);
void rboxid_clear_pixels(u8, u8);
void rboxid_08003FA0(u8);
void sub_0800F34C(void);
u8 sav2_get_text_speed(void);
void lz77_uncomp_vram(void* src, void* dst);

extern struct textflags textflags;
extern struct strings_to_display strings_to_display;

#endif /* TEXTBOX_RELATED_H */
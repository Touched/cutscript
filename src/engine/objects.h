#ifndef ENGINE_OBJECTS_H
#define ENGINE_OBJECTS_H

struct object;
typedef void (*object_callback)(struct object*);

typedef struct frame {
	u16 data;
	u16 duration;
} frame;

struct rotscale_frame {
	u16 scale_delta_x;
	u16 scale_delta_y;
	u8 rotation_delta;
	u8 duration;
	u16 field_6;
};

struct sprite {
	u32 y : 8;
	u32 rotscale : 1;
	u32 double_size : 1;
	u32 obj_mode : 2;
	u32 mosaic : 1;
	u32 colors : 1;
	u32 shape : 2;

	u32 x : 9;

	u32 rotscale_param : 3;
	u32 hflip : 1;
	u32 vflip : 1;	

	u32 size : 2; 

	u16 char_name : 10;
	u16 priority : 2;
	u16 palette : 4;
	
	u16 rotscale_info; 
};

struct resource {
	u8 *graphics;
	u32 size;
};

struct objtemplate {
	u16 tiles_tag;
	u16 pal_tag;
	struct sprite *oam;
	struct frame **animation;
	struct resource *graphics;
	struct rotscale_frame **rotscale;
	object_callback callback;
};

struct object {
	struct sprite final_oam;
	struct frame **animation_table;
	u8 *gfx_table;
	struct rotscale_frame **rotscale_table;
	struct objtemplate *template;
	u32 field18;
	object_callback callback;
	u16 x;
	u16 y;
	u16 x2;
	u16 y2;
	u8 x_centre;
	u8 y_centre;
	u8 anim_number;
	u8 anim_frame;
	u8 anim_delay;
	u8 counter;
	u16 private[8];
	u8 bitfield2;
	u8 bitfield;
	u16 anim_data_offset;
	u8 field42;
	u8 field43;
};

extern struct object objects[64];
u8 *obj_ids_to_display;
struct sprite * poke_oam_battle;
struct frame ** anim_poke;
struct rotscale_frame **rotscale_empty;
object_callback oac_nullsub;
u8 template_instanciate_forward_search(struct objtemplate *, u8, u8, u8);
void obj_delete(struct object *);

#endif /* ENGINE_OBJECTS_H */

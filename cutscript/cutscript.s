@ nop
@ Nothing
.macro cs_nop 
.byte 0
.endm

@ end
@ Terminates the script
.macro cs_end 
.byte 1
.endm

@ (&u32 label) -> [scr_cursor] --> true
@ scr_cursor = label
.macro cs_goto arg0
.byte 2
.word \arg0
.endm

@ (u16 var_ID, &u32 local_var.index) -> [local_var.index] --> true
@ sets the value of a local_var.index to be the value of a variable
.macro cs_ow_var_load arg0, arg1
.byte 3
.hword \arg0
.word \arg1
.endm

@ (u16 var_ID, u16 value) -> void --> true
@ sets variable to the value of local_var.index. Note, only last two bytes are transfered.
.macro cs_ow_var_set arg0, arg1
.byte 4
.hword \arg0
.hword \arg1
.endm

@ (u16 var_ID, &u32 local_var.index) -> [local_var.index] --> true
@ sets local_var.index to be equal to the pointer to variable.
.macro cs_ow_var_access arg0, arg1
.byte 5
.hword \arg0
.hword \arg1
.endm

@ (&u32 image, &u32 pal, &u32 local_var.index) -> [local_var.index] --> true
@ creates an OAM given pointers to pal and image. Put's it's ID in local var index
.macro cs_create_oam arg0, arg1, arg2
.byte 6
.word \arg0
.word \arg1
.word \arg2
.endm

@ (&u32 local_var.index, u8 mode) -> void --> true
@ Controls the display of a OAM with an ID stored in local_var.index.  Mode 0 = hide, Mode 1 = show
.macro cs_oam_display arg0, arg1
.byte 7
.word \arg0
.byte \arg1
.endm

@ (&u32 local_var.index, u8 x, u8 y) -> void --> true
@ Change X, Y position of an OAM with id in local_var.index.
.macro cs_oam_move arg0, arg1, arg2
.byte 8
.word \arg0
.byte \arg1
.byte \arg2
.endm

@ (&u32 local_var.index) -> [local_var.index] --> true
@ delete and free associated resources of an OAM with ID local_var.index
.macro cs_oam_del arg0
.byte 9
.word \arg0
.endm

@ (&u32 local_var.index, u8 speed, u8 x, u8 y) -> void --> true
@ progressively translate an OAM with ID local_var.index at a speed to location X, Y by incrementing or decrementing
.macro cs_oam_translate arg0, arg1, arg3, arg2
.byte 10
.word \arg0
.byte \arg1
.byte \arg3
.byte \arg2
.endm

@ (&u32 local_var.index, &u32 pal) -> void --> true
@ update OAM pal to pal. Old pal is overwritten.
.macro cs_oam_pal_update arg0, arg1
.byte 11
.word \arg0
.word \arg1
.endm

@ (u8 layer, &u32 tileset, &u32 tilemap) -> void --> true
@ Uploads tileset and tilemap to background layer.
.macro cs_bg_load arg0, arg1, arg2
.byte 12
.byte \arg0
.word \arg1
.word \arg2
.endm

@ (u8 ID, u8 mode) -> void --> true
@ Controls the display of a OAM with an ID stored in local_var.index.  Mode 0 = hide, Mode 1 = show
.macro cs_BG_display arg0, arg1
.byte 13
.byte \arg0
.byte \arg1
.endm

@ (u8 ID, u8 x, u8 y) -> void --> true
@ Change X, Y position of an BG.
.macro cs_BG_move arg0, arg1, arg2
.byte 14
.byte \arg0
.byte \arg1
.byte \arg2
.endm

@ (u8 ID) -> void --> true
@ delete and free associated resources of a BG
.macro cs_BG_del arg0
.byte 15
.byte \arg0
.endm

@ (u8 ID, u8 speed, u16 x, u16 y) -> void --> true
@ progressively translate an BG at a speed to location X, Y by incrementing or decrementing
.macro cs_BG_translate arg0, arg1, arg3, arg2
.byte 16
.byte \arg0
.byte \arg1
.hword \arg3
.hword \arg2
.endm

@ (u16 *pal, u16 offset, u16 size) -> void --> true
@ update BG pal to pal. Old pal is overwritten.
.macro cs_pal_load arg0, arg1, arg2
.byte 17
.word \arg0
.hword \arg1
.hword \arg2
.endm

@ (s8 speed, u8 from, u8 to, u16 color) -> void --> true
@     
@ fade screen to a color at speed fast
.macro cs_pal_fade arg0, arg1, arg3, arg2
.byte 18
.byte \arg0
.byte \arg1
.hword \arg3
.byte \arg2
.endm

@ (&u32 local_var.index, u8 direction) -> void --> true rotate an oam in a direction
.macro cs_oam_rotate arg0, arg1
.byte 19
.word \arg0
.byte \arg1
.endm

@ (&u32 local_var.index, u8 mode) -> void --> true
@ flip an oam on an axis
.macro cs_oam_flip arg0, arg1
.byte 20
.word \arg0
.byte \arg1
.endm

@ (&u32 local_var.index, u8 scale_size, u8 scale_mode) -> void --> true
@ change the scaling on an OAM
.macro cs_oam_zoom arg0, arg1, arg2
.byte 21
.word \arg0
.byte \arg1
.byte \arg2
.endm

@ (u32 length) -> void --> true
@ Wait length frames
.macro cs_pause arg0
.byte 22
.word \arg0
.endm


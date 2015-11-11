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
.macro cs_goto address
.byte 2
.byte \address
.endm

@ (u16 var_ID, &u32 local_var.index) -> [local_var.index] --> true
@ sets the value of a local_var.index to be the value of a variable
.macro cs_ow_var_load ow_var_id, var_id
.byte 3
.hword \ow_var_id
.hword \var_id
.endm

@ (u16 var_ID, u16 value) -> void --> true
@ sets variable to the value of local_var.index. Note, only last two bytes are transfered.
.macro cs_ow_var_set ow_var_id, value
.byte 4
.hword \ow_var_id
.hword \value
.endm

@ (u16 var_ID, &u32 local_var.index) -> [local_var.index] --> true
@ sets local_var.index to be equal to the pointer to variable.
.macro cs_ow_var_access ow_var_id, variable
.byte 5
.hword \ow_var_id
.hword \variable
.endm

@ (&u32 image, &u32 pal, &u32 local_var.index) -> [local_var.index] --> true
@ creates an OAM given pointers to pal and image. Put's it's ID in local var index
.macro cs_create_oam image, pal, var
.byte 6
.word \image
.word \pal
.word \var
.endm

@ (&u32 local_var.index, u8 mode) -> void --> true
@ Controls the display of a OAM with an ID stored in local_var.index.  Mode 0 = hide, Mode 1 = show
.macro cs_oam_display var, mode
.byte 7
.word \var
.byte \mode
.endm

@ (&u32 local_var.index, u8 x, u8 y) -> void --> true
@ Change X, Y position of an OAM with id in local_var.index.
.macro cs_oam_move var, x, y
.byte 8
.word \var
.byte \x
.byte \y
.endm

@ (&u32 local_var.index) -> [local_var.index] --> true
@ delete and free associated resources of an OAM with ID local_var.index
.macro cs_oam_del var
.byte 9
.word \var
.endm

@ (&u32 local_var.index, u8 speed, u8 x, u8 y) -> void --> true
@ progressively translate an OAM with ID local_var.index at a speed to location X, Y by incrementing or decrementing
.macro cs_oam_translate var, speed, x, y
.byte 10
.word \var
.byte \speed
.byte \x
.byte \y
.endm

@ (&u32 local_var.index, &u32 pal) -> void --> true
@ update OAM pal to pal. Old pal is overwritten.
.macro cs_oam_pal_update var, pal
.byte 11
.word \var
.word \pal
.endm

@ (u8 layer, &u32 tileset, &u32 tilemap) -> void --> true
@ Uploads tileset and tilemap to background layer.
.macro cs_bg_load layer, tileset, tilemap
.byte 12
.byte \layer
.word \tileset
.word \tilemap
.endm

@ (u8 ID, u8 mode) -> void --> true
@ Controls the display of a OAM with an ID stored in local_var.index.  Mode 0 = hide, Mode 1 = show
.macro cs_BG_display layer, mode
.byte 13
.byte \layer
.byte \mode
.endm

@ (u8 ID, u8 x, u8 y) -> void --> true
@ Change X, Y position of an BG.
.macro cs_BG_move layer, x, y
.byte 14
.byte \layer
.byte \x
.byte \y
.endm

@ (u8 ID) -> void --> true
@ delete and free associated resources of a BG
.macro cs_BG_del layer
.byte 15
.byte \layer
.endm

@ (u8 ID, u8 speed, u16 x, u16 y) -> void --> true
@ progressively translate an BG at a speed to location X, Y by incrementing or decrementing
.macro cs_BG_translate layer, speed, x, y
.byte 16
.byte \layer
.byte \speed
.hword \x
.hword \y
.endm

@ (u16 *pal, u16 offset, u16 size) -> void --> true
@ update BG pal to pal. Old pal is overwritten.
.macro cs_pal_load pal, offset, size
.byte 17
.word \pal
.hword \offset
.hword \size
.endm

@ (s8 speed, u8 from, u8 to, u16 color) -> void --> true
@     
@ fade screen to a color at speed fast
.macro cs_pal_fade speed, from, to, color
.byte 18
.byte \speed
.byte \from
.byte \to
.hword \color
.endm

@ (&u32 local_var.index, u8 direction) -> void --> true rotate an oam in a direction
.macro cs_oam_rotate var, direction
.byte 19
.word \var
.byte \direction
.endm

@ (&u32 local_var.index, u8 mode) -> void --> true
@ flip an oam on an axis
.macro cs_oam_flip var, mode
.byte 20
.word \var
.byte \mode
.endm

@ (&u32 local_var.index, u8 scale_size, u8 scale_mode) -> void --> true
@ change the scaling on an OAM
.macro cs_oam_zoom var, size, mode
.byte 21
.word \var
.byte \size
.byte \mode
.endm

@ (u32 length) -> void --> true
@ Wait length frames
.macro cs_pause length
.byte 22
.word \length
.endm


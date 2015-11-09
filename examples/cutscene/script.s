	.include "cutscript.s"

main:
	cs_bg_load 1, 0x084147C0, 0x084154E8
	cs_BG_display 1, 1
	cs_pal_load 0x08415954, 0, 0x40
	cs_pal_fade 0x3, 0x10, 0, 0x0000
	cs_pause 0xFF
	cs_end

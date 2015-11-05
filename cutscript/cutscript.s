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

@ goto address
@ Jump to a new script
@ This is a relative jump.
@ address - The value will be added to the program counter.
.macro cs_goto arg0
.byte 2
.word \arg0
.endm


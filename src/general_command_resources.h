struct saved_addr_stack {
	// linked list for stack
	u32 *linked_list_start;
	u32 *linked_list_size;
	u32 *linked_list_tail;
};

struct local_var{
	u8 status; // multipurpose status variable
	u32 vars[0x20]; // 0x20 local vars
};

struct enum bool{
	TRUE;
	FALSE;
};
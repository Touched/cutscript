#ifndef ENGINE_CALLBACK_H
#define ENGINE_CALLBACK_H

#include "types.h"

typedef void (*task_callback)(u8);
typedef void (*super_callback)(void);

struct task {
	task_callback function;
	bool inuse;
	u8 prev;
	u8 next;
	u8 priority;
	u16 priv[16];
};

u8 task_add(task_callback func, u8 priority);
void task_del(u8 id);

void set_callback2(super_callback func);
void set_callback1(super_callback func);

#endif /* ENGINE_CALLBACK_H */

#ifndef ENGINE_MEMORY_H
#define ENGINE_MEMORY_H

#include "types.h"

void *malloc(u32 size);
void *malloc_and_clear(u32 size);
void free(void *ptr);
void *malloc_and_LZ77UnComp(u8 *tiles, u16 *size);

#endif /* ENGINE_MEMORY_H */

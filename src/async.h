#ifndef ASYNC_H
#define ASYNC_H

void async_spawn(command_function func, u32 *args);
void async_exec(void);

#endif /* ASYNC_H */

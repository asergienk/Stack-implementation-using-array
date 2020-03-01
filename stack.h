#include "status.h"

typedef void* STACK;

STACK stack_init_default(void);
void stack_destroy(STACK* phStack);
Status stack_push(STACK hStack, int number);
Status stack_pop(STACK hStack);
Boolean stack_empty(STACK hStack);
int stack_top(STACK hStack, Status* status);
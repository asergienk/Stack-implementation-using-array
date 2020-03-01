#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    int i;
    STACK hStack;
    hStack = stack_init_default();
    if(hStack == NULL)
    {
        printf("Failed to allocate memory for hStack object\n");
        exit(1);
    }
    
    stack_push(hStack, 4);
    stack_push(hStack, 6);
    stack_push(hStack, 8);
    stack_push(hStack, 10);
    
    
    stack_pop(hStack);
    
    while(!stack_empty(hStack))
    {
        printf("%d\n", stack_top(hStack, NULL));
        stack_pop(hStack);
        if(stack_empty(hStack))
        {
            printf("Stack is empty\n");
        }
    }
    
    stack_destroy(&hStack);

    return 0;
}

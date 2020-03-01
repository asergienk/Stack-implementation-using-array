#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack
{
    int size;
    int capacity;
    int* data;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
    
    Stack* pStack;
    pStack = (Stack*)malloc(sizeof(Stack));
    if(pStack!=NULL)
    {
        pStack->size=0;
        pStack->capacity=7;
        pStack->data = (int*)malloc(sizeof(int) * pStack->capacity);
        if(pStack->data == NULL)
        {
            free(pStack);
            return NULL;
        }
    }
        return (STACK) pStack;
}


void stack_destroy(STACK* phStack)
{
    Stack* pStack = (Stack*)* phStack;
    free(pStack->data);
    free(pStack);
    *phStack = NULL;
    //printf("Destroyification complete\n");
}



Status stack_push(STACK hStack, int number)
{
    int* temp;
    int i;
    Stack* pStack = (Stack*) hStack;
    //if there is no room, make room
    if(pStack->size >= pStack->capacity)
    {
        temp=(int*)malloc(sizeof(temp) * pStack->capacity * 2);
        if(temp==NULL)
        {
            return FAILURE;
        }
        for(i=0; i<pStack->size; i++)
        {
            temp[i]=pStack->data[i];
        }
        pStack->capacity *= 2;
        free(pStack->data);
        pStack->data=temp;
    }
    //now assume there is room so place the item in
    pStack->data[pStack->size] = number;
    pStack->size++;
    return SUCCESS;
}

Status stack_pop(STACK hStack)
{
    Stack* pStack = (Stack*) hStack;
    
    if(pStack->size <= 0)
    {
        return FAILURE;
    }
    
    pStack->size--;
    return SUCCESS;
}

Boolean stack_empty(STACK hStack)
{
    Stack* pStack = (Stack*) hStack;
    return (Boolean) pStack->size <=0;
}


int stack_top(STACK hStack, Status* pStatus)
{
    Stack* pStack = (Stack*) hStack;
    
    if(stack_empty(hStack))
    {
        if(pStatus != NULL)
        {
        *pStatus= FAILURE;
        }
        return -31337;
    }
    if(pStatus != NULL)
        {
        *pStatus= SUCCESS;
        }
    return pStack->data[pStack->size-1];
}
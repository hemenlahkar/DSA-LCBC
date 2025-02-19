/* This header file contains all functions and variable required to implement stack using Array
    Author: Hemen Lahkar
    Date: 19-Feb-2025
*/

#ifndef MYSTACK
#define MYSTACK

#include <stdlib.h>
#include <stdio.h>

typedef struct stack_arr
{
    int size;
    int top;
    int *arr;
} stackArr;

stackArr *stack_arr_constructor(int size)
{
    stackArr *s = (stackArr *)malloc(sizeof(stackArr));
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(size * sizeof(int));
    return s;
}

stackArr *stack_arr_destructor(stackArr *ptr)
{
    free(ptr->arr);
    free(ptr);
}

int isFullArr(stackArr *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

int isEmptyArr(stackArr *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

void pushArr(stackArr *ptr, int n)
{
    if (isFullArr(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack!\n", n);
        return;
    }
    ptr->arr[++ptr->top] = n;
}

int popArr(stackArr *ptr)
{
    if (isEmptyArr(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

int peekArr(stackArr *sp, unsigned int i)
{
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0)
    {
        printf("Not a valid position for the stack!\n");
        return -1;
    }
    return sp->arr[arrayInd];
}

#endif
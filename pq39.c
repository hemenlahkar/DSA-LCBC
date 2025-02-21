#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *node)
{
    if (node->top == node->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct stack *node)
{
    if (node->top == -1)
        return 1;
    return 0;
}

void push(struct stack *node, int value)
{
    if (isFull(node))
        return;
    node->arr[++node->top] = value;
}

int pop(struct stack *node)
{
    if (isEmpty(node))
        return -1;
    int x = node->arr[node->top];
    node->top--;
    return x;
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;

    push(s, 3);
    push(s, 5);
    printf("%d", pop(s));
    printf("%d", pop(s));
}
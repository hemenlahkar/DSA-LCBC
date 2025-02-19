#include <stdio.h>
#include "Headers/mystack.h"

int main()
{
    stackArr *s1 = stack_arr_constructor(10);
    printf("%d\n", s1->top);
    pushArr(s1, 5);
    printf("%d\n", s1->top);
    printf("%d\n", popArr(s1));
    stack_arr_destructor(s1);
}
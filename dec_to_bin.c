#include <stdio.h>
#include "Headers/mystack.h"
int main()
{
    int number;
    stackArr *s = stack_arr_constructor(100);
    printf("Enter the decimal integer: ");
    scanf("%d", &number);
    while (number != 0)
    {
        pushArr(s, number % 2);
        number /= 2;
    }
    while (!isEmptyArr(s))
    {
        printf("%d", popArr(s));
    }
    stack_arr_destructor(s);
    return 0;
}
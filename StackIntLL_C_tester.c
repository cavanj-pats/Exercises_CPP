//StackIntLL_C_tester.c




#include <stdio.h>
#include <stdlib.h>
#include "StackIntLL_C.h"



int main()
{
    struct Stack * st;
    createStack(st);
    
    
    push(st, 17);
    push(st, 9);
    push(st, 1);

    printf("Peek at item position 2: %d\n", peek(st, 2));
    
    display(st);

    printf("Pop Top: %d\n\n", pop(st));


    display(st);

        return 0;

}
    
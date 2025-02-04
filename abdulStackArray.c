//abdul Stack   lecture 232
//abdulStackArray.c

#include <stdio.h>
#include <stdlib.h>


struct Stack
{
    int size;
    int top;
    int * s;
};

void push(struct Stack * st, int x)
{
    st->s[++st->top] = x;
      //top is number of elements. top element on largest index
}

int peek(struct Stack * st)
{
    return st->s[st->top];  

}

int pop(struct Stack * st)   //delete the top value
{
    int val = st->s[st->top];
    st->top--;
    return val;
}

void printStack(struct Stack * st)
{
    for(int i = st->top ; i>= 0; i--)
        printf("%d\n", st->s[i]);

}


int main()
{
    struct Stack * st;



    printf("Please enter size of Stack: ");
    scanf("%d", &st->size);
    st->top = -1;   //set initial size of Stack
    st->s =  (int *) malloc(st->size * sizeof(int));
    push(st,4);
    push(st,9);
    
    printf("Peek at top value: %d\n", peek(st));
    printStack(st);


    return 0;


}


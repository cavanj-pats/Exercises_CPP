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

void createStack(struct Stack *st, int size)
{
    st->s = (int *) malloc(size * sizeof(int));
    st->top = -1;
    st->size = size;
}

void push(struct Stack * st, int x)
{
    if(st->top < st->size-2)
        st->s[++st->top] = x;
      //top is number of elements. top element on largest index
}

int peek(struct Stack st,  int pos)
{
    //abdul's peek takes a stack by value and a position
    //he derived an expression to determine array index.
    //it is ::  [top - position + 1]

    int x = -1;

    //verify pos is valid.
    if(st.top - pos + 1 < 0)
    {
        printf("Invalid Position!\n");
    }
    else{
        x =  st.s[st.top - pos + 1];  
    }

    return x;
}

int pop(struct Stack * st)   //delete the top value
{
    int x = -1;
    if(st->top == -1)
    {
        printf("Stack is empty return -1\n");
    }
    else 
    {
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

void printStack(struct Stack * st)
{
    for(int i = st->top ; i>= 0; i--)
        printf("%d\n", st->s[i]);

}

int isFull(struct Stack st)
{
    if(st.top == st.size- 1)
        return 1;

    return 0;
}

int isEmpty(struct Stack st)
{
    if(st.top == -1) return 1;

    return 0;
}


int main()
{
    struct Stack * st;
    int sz;


    printf("Please enter size of Stack: ");
    scanf("%d", &sz);
    createStack(st, sz);
    
    push(st,4);
    push(st,9);
    
    printf("Peek at top value: %d\n", peek(*st,1));
    printStack(st);


    return 0;


}


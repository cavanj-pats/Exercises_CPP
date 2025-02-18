//LList based stack
//
//StackIntLL_C.h

#include <stdio.h>
#include <stdlib.h>

#include "QueueLLTreeNodeC.h"   //this allows Stack to use the same Node as Queue for use in Tree

//abdul used only struct Node he did not use struct Stack.  
// all functions were written based on Node but create teh stack interface






struct Stack
{
    struct Node *top;
};



void createStack(struct Stack * st)
{
    //invoke this to initialize the Stack
   
    st->top= (struct Node *) malloc(sizeof(struct Node));
    st->top = NULL;

}



void push(struct Stack *st, uintptr_t value)
{
    struct Node * p;
    p=(struct Node *) malloc(sizeof(struct Node));
    if(p == NULL)
        printf("Data not pushed. Perhaps memory full.\n");
    else
    {    
        p->data = value;
        p->next = st->top;
        st->top = p;
    }

}

uintptr_t pop(struct Stack *st)
{
    long int x = -1;
    struct Node *p;

    if(st->top == NULL)
    {
        printf("Stack is emtpy!\n");
    }
    else
    {
        x = st->top->data;
        p= st->top;
        st->top = st->top->next;
        free( p);
        
    }

    return x;

}

int isEmpty_stack(struct Stack *st)
{
    return st->top == NULL ? 1 : 0 ;
}

int isFull_stack()
{
    struct Node * t;
    t = (struct Node *) malloc(sizeof(struct Node));

    return t == NULL ? 1 : 0 ;
    
}

uintptr_t peek(struct Stack *st, int pos)
{
    struct Node * p;
    p = st->top;
    
    for(int i = 0;p !=NULL && i<pos-1; i++ )
        p = p->next;

    if(p == NULL)
        printf("No Node is present. \n");

       return  p ? p->data : -1 ;

}

void displayStack(struct Stack *st)
{
    struct Node * p;
    p = st->top;

    if (st->top == NULL)
        printf("No Node Present.\n");

    while (p)
    {
        printf("%d, ",p->data);
        p = p->next;

    }
    
    printf("\n");
}






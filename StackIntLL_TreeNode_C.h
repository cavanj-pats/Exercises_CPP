//LList based stack
//
//StackIntLL_C.h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

//#include "QueueLLTreeNodeC.h"   //this allows Stack to use the same Node as Queue for use in Tree

//abdul used only struct Node he did not use struct Stack.  
// all functions were written based on Node but create teh stack interface


struct stackNode
{
    long long int data;
    struct stackNode * next;
} ;//removed *top = NULL



struct Stack
{
    struct stackNode *top;
};



void createStack(struct Stack * st)
{
    //invoke this to initialize the Stack
   
    st->top= (struct stackNode *) malloc(sizeof(struct stackNode));
    st->top = NULL;

}



void push(struct Stack *st, long long int value)
{
    struct stackNode * p;
    p=(struct stackNode *) malloc(sizeof(struct stackNode));
    if(p == NULL)
        printf("Data not pushed. Perhaps memory full.\n");
    else
    {    
        p->data = value;
        p->next = st->top;
        st->top = p;
    }

}

long long int pop(struct Stack *st)
{
    long long int  x = -1;
    struct stackNode *p;

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
    struct stackNode * t;
    t = (struct stackNode *) malloc(sizeof(struct stackNode));

    return t == NULL ? 1 : 0 ;
    
}

long long int peek(struct Stack *st, int pos)
{
    struct stackNode * p;
    p = st->top;
    
    for(int i = 0;p !=NULL && i<pos-1; i++ )
        p = p->next;

    if(p == NULL)
        printf("No Node is present. \n");

       return  p ? p->data : -1 ;

}

void displayStack(struct Stack *st)
{
    struct stackNode * p;
    p = st->top;

    if (st->top == NULL)
        printf("No Node Present.\n");

    while (p)
    {
        printf("%lld, ",p->data);    //need to be able to print uintptr_t data
        p = p->next;

    }
    
    printf("\n");
}






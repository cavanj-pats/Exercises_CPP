//LList based stack
//abdulStackLList.c

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    struct Node *s;
};

struct Node
{
    int data;
    struct Node * next;
} *head;



void createStack(struct Stack * st, int size)
{
    struct Node * head = NULL;
    //size is the total size of the stack
    st->size = size;
    st->top = -1;
    st->s = (struct Node *) malloc(size * sizeof(struct Node));
    

}

void push(struct Stack * st, int value)
{
    struct Node * p;
    p=(struct Node *) malloc(sizeof(struct Node));
    p->data = value;
    
    
    if(st->top == -1)
    {
        p->next = NULL;
    }
    else
    {
        p->next = head;
    }

    head = p;
    st->s = head;
    st->top++;

}

int peek(struct Stack st, int pos)
{
    struct Node * p;
    p =  st.s;
}






int main()
{
    struct Stack * st;
    createStack(st, 10);
    
    push(st,17);
    push(st, 9);
    push(st, 1);

    


    return 0;

}
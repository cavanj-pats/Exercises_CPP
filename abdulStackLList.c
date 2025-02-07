//LList based stack
//abdulStackLList.c

#include <stdio.h>
#include <stdlib.h>

//abdul used only struct Node he did not use struct Stack.  
// all functions were written based on Node but create teh stack interface

/*
struct Stack/
{
    int size;
    int top;
    struct Node *s;
};
*/
struct Node
{
    int data;
    struct Node * next;
} *top = NULL;


/*
void createStack(struct Stack * st, int size)
{
    struct Node * head = NULL;
    //size is the total size of the stack
    st->size = size;
    st->top = -1;
    st->s = (struct Node *) malloc(size * sizeof(struct Node));
    

}
*/

void push(int value)
{
    struct Node * p;
    p=(struct Node *) malloc(sizeof(struct Node));
    if(p == NULL)
        printf("Data not pushed. Perhaps memory full.\n");
    else
    {    
        p->data = value;
        p->next = top;
        top = p;
    }

}

int pop()
{
    int x = -1;
    struct Node *p;

    if(top == NULL)
    {
        printf("Stack is emtpy!\n");
    }
    else
    {
        x = top->data;
        p= top;
        top = top->next;
        delete p;
        return x;
    }

    return x;

}

int isEmpty()
{
    return top == NULL ? 1 : 0 ;
}

int isFull()
{
    struct Node * t;
    t = (struct Node *) malloc(sizeof(struct Node));

    return t == NULL ? 1 : 0 ;
    
}

int peek(int pos)
{
    struct Node * p;
    p = top;
    
    for(int i = 0;p !=NULL && i<pos-1; i++ )
        p = p->next;

    if(p == NULL)
        printf("No Node is present. \n");

       return  p ? p->data : -1 ;

}

void display()
{
    struct Node * p;
    p = top;

    if (top == NULL)
        printf("No Node Present.\n");

    while (p)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
}





int main()
{
    //struct Node * st;
    
    
    push(17);
    push( 9);
    push( 1);

    printf("Peek at item position 2: %d\n", peek(2));
    
    display();

    printf("Pop Top: %d\n\n", pop());


    display();

    


    


    return 0;

}
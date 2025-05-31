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
    char data;
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

void push(char value)
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

char pop()
{
    char x = -1;
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
        free (p);
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

char peek(int pos)
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
        printf("%c\n",p->data);
        p = p->next;
    }
}


int isBalanced(char *s)
{
    int i = 0;
    
    //determine if parentheses are balanced
    while(s[i] != '\0')
    {
        if (s[i] == '(' )
            push(s[i]);

        if(s[i] == ')')
           // if (isEmpty)
           //     return 0;  //if the string is empty yet we have to pop then it is not balanced
            pop();  //string is not empty so pop

        i++;
    }

    return isEmpty() ? 1 : 0 ;
}

int isBalancedBracket(char *s)
{
    //use ascii values to create a balance score
    int i = 0;
    int balanceScore = 0;
    char poppedItem;
    
    //determine if parentheses are balanced
    while(s[i] != '\0')
    {
        if (s[i] == '('  || s[i] == '{' || s[i] == '[')
            push(s[i]);

        if(s[i] == ')')
        {   
           poppedItem= pop();  //string is not empty so pop
           balanceScore+=s[i]-poppedItem - 1;  //should be zero
           if(balanceScore != 0) return 0;
        }
        else if(s[i] == '}'  || s[i] == ']')
        {
            poppedItem= pop();  //string is not empty so pop
            balanceScore+=s[i]-poppedItem - 2;
            if(balanceScore != 0) return 0;
        }

        i++;
    }

    return (isEmpty() && balanceScore == 0) ? 1 : 0 ;
}




int main()
{
    //struct Node * st;
    char * s = "{{(a+b)*n}/j + [r-g]}";
    
    //push('a');
    //push( 'z');
    //push('q');

    //printf("Peek at item position 2: %c\n", peek(2));
    
   // display();

    //printf("Pop Top: %c\n\n", pop());


    //display();

    printf("Is Balanced: %d", isBalancedBracket(s));



    


    return 0;

}
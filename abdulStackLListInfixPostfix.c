//LList based stack
//abdulStackLList.c
//use a Stack to convert an infix expression to Postfix using Abdul's process of 
//pushing and popping based on precedence
/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
higher precedence has higher number
push if precedence is higher than top or stack is empty
pop if precedence is lower

Symbol  Precedence  Associativity
------- ----------  --------------
+ , -     1            L - R
* , /     2            L - R
a, b, c   3            L - R

*/

struct Node
{
    char data;
    struct Node * next;
} *top = NULL;

char pop();
void push(char );
int operand(char );
int precedence(char);
int isEmpty();



char * infixToPrefix(char * s)
{
    int i = 0;
    int k = 0;
    
    //array to hold the postfix equation
    char * postfx;
    postfx = (char *)malloc(strlen(s) * sizeof(char));


    struct Node * t;
    
//could have also used a while s[i]!='\0'

    while(s[i]!='\0')
    {
        

        if(isEmpty() || precedence(s[i]) > precedence(top->data))
        {
           push(s[i++]);
        }
        else
        {
            //stack is not empty and precedence is less than top
            while(!isEmpty() && precedence(s[i]) <= precedence(top->data))
            {
                postfx[k++] = pop();
                
            }
            
            
            push(s[i++]);
        }
            
    }

    while (!isEmpty())
    {
        postfx[k++] = pop();
        
    }
    postfx[k]='\0';

    return postfx;

}

//helper functions
int operand(char c)
{
    if ( c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    else    
        return 0;
}

int precedence(char c)
{
    if (operand(c))
    {
        if(c == '*'| c == '/')
            return 2;
        else if ( c == '+' || c == '-')
            return 1;
        else
            return 0;
    }
    else
    {
         //is operand
        return 3;
    }
        
}



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
    char * s = "a+b*c-d/e";
    char * postfx;
    
    //push('a');
    //push( 'z');
    //push('q');

    //printf("Peek at item position 2: %c\n", peek(2));
    
   // display();

    //printf("Pop Top: %c\n\n", pop());


    //display();

    //printf("Is Balanced: %d", isBalancedBracket(s));
    postfx = infixToPrefix(s);
    for(int i=0; i<strlen(s);i++)
        printf("%c",s[i]);

    printf("\n");

    for(int i=0; i<strlen(s);i++)
        printf("%c",postfx[i]);

    printf("\n");

    


    return 0;

}
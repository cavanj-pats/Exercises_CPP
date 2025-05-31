//LList based stack
//abdulStackLListInfixPosfix2.c
//use a Stack to convert an infix expression to Postfix using Abdul's process of 
//pushing and popping based on precedence
//this version has parentheses and brackets and different precedence whether the item is 
//in the stack or not.   
/*

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
higher precedence has higher number
push if precedence is higher than top or stack is empty
pop if precedence is lower

        out stack
Symbol  Precedence  In Stack Pre        Associativity
------- ----------  -------------      --------------
+ , -     1              2                L - R
* , /     3              4                L - R
  ^       6              5                R - L
  (       7              0                L - R
  )       0              ?            //never put in stack 
  a, b, c   3                            L - R  //never put in stack

*/

struct Node
{
    char data;
    struct Node * next;
} *top = NULL;

char pop();
void push(char );
int operand(char );
int precOut(char);
int precIn(char);
int isEmpty();



char * infixToPrefix(char * s)
{
    int i = 0;
    int k = 0;
    
    //array to hold the postfix equation
    char * postfx;
    char temp;
    postfx = (char *)malloc((strlen(s)) * sizeof(char));


    struct Node * t;
    
//could have also used a while s[i]!='\0'

    while(s[i]!='\0')
    {
        
        if(isEmpty())
        {
            if(operand(s[i]))
                postfx[k++] = s[i++];  //no need to push onto stack
            else if(precOut(s[i])== 0)
                i++;  //skip it is a closing ')'    
            else
                push(s[i++]);  //is is an operand

        }
        else
        {
            if(operand(s[i]) )
            {


                //put directly onto the string
                postfx[k++] = s[i++];  //no need to push onto stack

            } else if(precOut(s[i]) > precIn(top->data))
            {
                push(s[i++]);
            }
            else
            {
                while(!isEmpty() && precOut(s[i]) <= precIn(top->data))
                {
                    temp = pop();
                    if(precIn(temp) != 0)
                        postfx[k++] =  temp;
                }    
                        
                push(s[i++]);  //it is an operator and all higher precedence have been popped   
            }
        
        
        }
                
    }
       
    while (!isEmpty())
    {
        temp = pop();
        if(precIn(temp) != 0)
            postfx[k++] =  temp;
        
    }
       
       
    while(k<i-1)
        postfx[k++] = '#';
    
    postfx[k]='\0';

    return postfx;

}

//helper functions
int operand(char c)
{
    if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return 0;
    else    
        return 1;
}

int precOut(char c)
{
    //out of stack
    
    if(c == '*' || c == '/')
        return 3;
    else if ( c == '+' || c == '-')
        return 1;
    else if( c == '^')
        return 6;
    else if(c == '(')
        return 7;
    else
        return 0;   //these will go directly to the string
}

int precIn(char c)
{
    //out of stack
    
    if(c == '*' || c == '/')
        return 4;
    else if ( c == '+' || c == '-')
        return 2;
    else if( c == '^')
        return 5;
    else if(c == '(')
        return 0;  // keep in here in case later i need to give it a value
    else
        return 0;   //these will go directly to the string
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
    //char * s = "a+b*c-d/e";
    char * s = "a+b*(c+d)/f+d*e";
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
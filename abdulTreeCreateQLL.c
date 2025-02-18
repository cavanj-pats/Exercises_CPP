//create Tree  C   queue Link List

//abdulTreeCreateQLL.c

#include <stdio.h>
#include <stdlib.h>
#include "QueueLLTreeNodeC.h"  //queue holds the tree Nodes
#include "StackIntLL_TreeNode_C.h"   //needs to be modified to hold tree nodes (I think)



struct Node *root;

void createTree()
{
    int x;
    struct Node *p;
    struct Node *t;
   // struct Queue *q;
    

    printf("Enter Root Node Value (-1) to quit: ");
    scanf("%d", &x );
    root = (struct Node *)malloc(sizeof(struct Node));
    //q = (struct Node **)malloc(sizeof(Node*));
    
   // create(q, root);
    
    root->data = x;
    root->next = NULL;
    root->left = NULL;
    root->right = NULL;

    enqueue(root, x);
    p = root;

    while(!isEmpty(p))
    {
        p = dequeue();

        printf("\n Enter Left Child of %d (-1) to terminate: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *) malloc(sizeof(struct Node));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->left = t;

            enqueue(t,x);

        }

        printf("\n Enter Right Child of %d (-1) to terminate: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct Node *) malloc(sizeof(struct Node));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            p->right = t;
            
            enqueue(t ,x);

        }



    }

    

}


void preorder(struct Node * p){
    if (p){
        printf("%d, ", p->data) ;
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct Node * p){
    if (p){
        
        inorder(p->left);
        printf("%d, ", p->data) ;
        inorder(p->right);
    }
}
 
void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d, ", p->data) ;
    }
}

//iterative Traversal
/*

void preorder(struct Node *t)
{
    struct Stack st;  //need to define this 
    createStack(&st);

    while( t != NULL || isEmpty(st))
    {
        if(t != NULL)
        {
            printf("%d", t->data);
            push(&st, t);
            t = t->left;
        }
        else
        {
            t = pop(&st);
            t = t->right;
        }
    }
}//preorder iterative


void inorder(struct Node *t)
{
    struct Stack st;  //need to define this 
    createStack(&st);

    while( t != NULL || isEmpty(st))
    {
        if(t != NULL)
        {
            push(&st, t);
            t = t->left;
        }
        else
        {
            t = pop(&st);
            printf("%d", t->data);
            t = t->right;
        }
    }
}//inorder iterative
*/

void itpostorder(struct Node *t)
{
    struct Stack st;  //need to define this 
    createStack(&st);
    long int temp;    //when pushing an address for a second time change it's sign so you know why you pushed it
    while( t != NULL || !isEmpty_stack(&st))
    {
        if(t != NULL)
        {
            push(&st, ((long int) t) ); //need to be able to hold tree nodes in this stack
            t = t->left;
        }
        else
        {
            temp = pop(&st);
            if(temp > 0)
            {
                push(&st, -temp);
                t = ((struct Node *)temp)->right;  //typcast the integer into an pointer
            }
            else
            {
                printf("%d", ((struct Node *) (-temp))->data);
                t = NULL;   //not sure why this
            }
            
        }
    }
}//postorder iterative





int main() {
 
    createTree();
 
    printf ( "Preorder: " );
    preorder(root);
    printf("\n");
    
    printf ( "Inorder: " );
    inorder(root);
    printf("\n");
    
    printf ( "Postorder: " );
    postorder(root);
    printf("\n");

    printf ( "Postorder: " );
    itpostorder(root);
    printf("\n");
 
    return 0;
}
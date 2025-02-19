//create Tree  C   queue Link List

//abdulTreeCreateQLL.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
//#include "QueueLLTreeNodeC.h"  //queue holds the tree Nodes
#include "StackIntLL_TreeNode_C.h"   //needs to be modified to hold tree nodes (I think)
                                     //stack incorporates QueueLLTreeNodeC.h
#include "QueueLLQueueNode_Int_C.h"  //this is a queue that can hold Node addresses as LongLongInt



struct queueNode *root;

void createTree()
{
    int x;  //still stores the data value
    struct queueNode *p;
    struct queueNode *t;
    //struct queueNode *root;
    
    struct Queue *q;
    

    printf("Enter Root Node Value (-1) to quit: ");
    scanf("%d", &x );
   // root = (struct queueNode *)malloc(sizeof(struct queueNode));
    q = (struct Queue *)malloc(sizeof(struct Queue));
    
    createQueue(q);
    
    root->data = x;
    root->next = NULL;
    root->left = NULL;
    root->right = NULL;

    enqueue(q, root);
    p = q->front;

    while(!isQueueEmpty(q))
    {
        p = (dequeue(q));    //cast as a queueNode

        printf("\n Enter Left Child of %d (-1) to terminate: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct queueNode *) malloc(sizeof(struct queueNode));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            t->next = NULL;
            p->left = t;

            enqueue(q, t);

        }

        printf("\n Enter Right Child of %d (-1) to terminate: ", p->data);
        scanf("%d", &x);
        if(x != -1)
        {
            t = (struct queueNode *) malloc(sizeof(struct queueNode));
            t->data = x;
            t->left = NULL;
            t->right = NULL;
            t->next = NULL;
            p->right = t;
            
            enqueue(q, t);

        }



    }

    

}


void preorder(struct queueNode * p){
    if (p){
        printf("%d, ", p->data) ;
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(struct queueNode * p){
    if (p){
        
        inorder(p->left);
        printf("%d, ", p->data) ;
        inorder(p->right);
    }
}
 
void postorder(struct queueNode *p)
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

void itpostorder(struct queueNode *t)
{
    struct Stack st;  //need to define this 
    createStack(&st);
    long long int temp;    //when pushing an address for a second time change it's sign so you know why you pushed it
    while( t != NULL || !isEmpty_stack(&st))
    {
        if(t != NULL)
        {
            push(&st, ((long long int) t) ); //need to be able to hold tree nodes in this stack
            t = t->left;
        }
        else
        {
            temp = pop(&st);
            if(temp > 0)
            {
                push(&st, -temp);
                t = ((struct queueNode *)temp)->right;  //typcast the integer into an pointer
            }
            else
            {
                printf("%d, ", ((struct queueNode *) (-temp))->data);
                t = NULL;   //not sure why this
            }
            
        }
    }
}//postorder iterative


//might need to go back to StackNode type to isolate the data type uintptr_t from that of the Tree Nodes
//which are holding integer data/values
//can't use uintptr_t as it is unsigned. i need to have a signed integer so i use long long int
//64 bit machines use longer addresses


void levelOrderTraversal(struct queueNode *p)
{
    //traverse a tree level by level
    //use a queue to hold a root and left child right child addresses
    struct Queue *q;
    q = (struct Queue *) malloc(sizeof(struct Queue));
    createQueue(q);
    
    if(p)
    {
        printf("%d, ",p->data);
        enqueue(q, p );
    }
    
    

    while(!isQueueEmpty(q))
    {
        p =  (dequeue(q));
        if(p->left)
        {
            printf("%d, ", p->left->data);
            enqueue(q, ((p->left)));            
        }
        if(p->right)
        {
            printf("%d, ", p->right->data);
            enqueue(q, (p->right));
        }
    }
    

    

}




int main() {
    
    root = (struct queueNode *)malloc(sizeof(struct queueNode));

    createTree(); //defines root
 
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
    
    printf("Level Order Traversal:");
    levelOrderTraversal(root);


    return 0;
}
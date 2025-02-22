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


//abdul made an even sipmler count function
int count(struct queueNode * root)
{
    int x, y;
    if(root)
    {
        x = count(root->left);
        y = count(root->right);
        return x+y+1;
    }

    return 0;
}

int abdulCount(struct queueNode *root)
{
    if (root)
        return abdulCount(root->left) + abdulCount(root->right) + 1;

    return 0;
}


//this appears to be returning the height of the tree
int fun(struct queueNode * root)
{
    int x, y;
    if(root)
    {
        x = fun(root->left);
        y = fun(root->right);
        if(x>y)
            return x+1;
        else
            return y+1;
    }

    return 0;
}

int countLeaf(struct queueNode * root)
{
    int x, y;
    if(root == NULL)
    {
       return 0;
    }
       
    if(root->left == NULL && root->right == NULL)
        return 1;

    return countLeaf(root->left)+ countLeaf(root->right);
        
}

 //the below was what he covered on whiteboard in lecture 
 //these are degree zero nodes.  you can also count degree 1 and 2 nodes by changing if
int abdulcount(struct queueNode * root)
{
    int x, y;
    if(root)
    {
        x = abdulcount(root->left);
        y = abdulcount(root->right);
        if (root->left == NULL && root->right == NULL)
        {
            return x+y+1;
        }
        else
            return x+y;
        
    }

    return 0;
}

/*
      degree 0     :  !left && !right    (aka leaf nodes)
      degree 2     :   left && right
      degree 1 or 2:   left || right
      degree 1     :   if left && ! right  ||  !left && right   or you can use exclusive OR
                      if (!left ^ !right)  //exclusive OR simplifies this expression greatly
*/



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

    printf("\n");
    printf("Node Count: %d", count(root));

    printf("\n");
    printf("Abdul Count: %d", abdulCount(root));

    printf("\n");
    printf("Leaf Count: %d", countLeaf(root));

    printf("\n");
    printf("Function 'fun' output: %d", fun(root));



    return 0;
}
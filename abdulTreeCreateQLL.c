//create Tree  C   queue Link List

//abdulTreeCreateQLL.c

#include <stdio.h>
#include <stdlib.h>
#include "QueueLLTreeNodeC.h"



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
 
    return 0;
}
//Binary Search Tree - Insert

//abdulBST.c   //i'll plan to build on this file



#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node * lchild;
    int data;
    struct Node * rchild;
}*root = NULL;

void BSTInsert(int value)
{
    //takes a value and 1) Creates a new Node and 2)Inserts the new Node in the appropriate position.
    //need a trailing pointer
    struct Node *t = NULL;
    struct Node *p = NULL;
    p = (struct Node*) malloc(sizeof(struct Node));


    if(root == NULL)
    {
        //first node
        p->data = value;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
        
    }
    else
    {
        p = root;
        while(p)
        {
            if(value < p->data)
            {
                t = p;
                p = p->lchild;
            }
            else if (value > p->data)
            {
                t = p;
                p = p->rchild;
            }
            else
            {
                //value == p->data (nothing to insert or data already inserted)
                return;
            }

        }
        //p is null and t is the parent node
        p = (struct Node*)malloc(sizeof(struct Node));
        p->lchild = NULL;
        p->rchild = NULL;
        p->data = value;
        if(p->data < t->data)
            t->lchild = p;
        else
            t->rchild = p;
        

    }

}

struct Node * BSTInsert_rec(struct Node* p, int key)
{
    //takes a value and 1) Creates a new Node and 2)Inserts the new Node in the appropriate position.
    //need a trailing pointer
    struct Node *t = NULL;
    
    //p = (struct Node*) malloc(sizeof(struct Node));


    if(p == NULL)
    {
        //first node
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
       return t;
        
        
    }
    
      
        
    if(key < p->data)
    {
        p->lchild = BSTInsert_rec(p->lchild, key);
    }
    else if (key > p->data)
    {
        
        p->rchild = BSTInsert_rec(p->rchild, key);
    }
    else if(key == p->data)
    {
        return p;
    }


    

    return p;   //I had return t but that is wrong. t only is defined if p is null
    //so this was a bug.  the only items that it was returning were 50 and 25  The first call after root 
    //and the last call after root.  Exactly one left child and one right child
    //this code will assign a child to p then return p on this line after the recursive call returns
    //actually quite interesting.

}


void inorder(struct Node * p){
    if (p){
        
        inorder(p->lchild);
        printf("%d, ", p->data) ;
        inorder(p->rchild);
    }
}



int main()
{
    root = NULL;
    root = BSTInsert_rec(root, 30);
    BSTInsert_rec(root, 50);
    BSTInsert_rec(root, 20);
    BSTInsert_rec(root, 10);
    BSTInsert_rec(root, 25);

    inorder(root);

    return 0;

}
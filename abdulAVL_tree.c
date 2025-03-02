//abdulAVL_tree.c
//3/1/2025


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node * lchild;
    int data;
    int height;
    struct Node * rchild;
}*root = NULL;


//this appears to be returning the height of the tree
//this is from binary tree and is fine. but he wrote a new function that is cool so i want to put it here.


void Insert(int key)
{
    struct Node *t=root;
    struct Node *r=NULL,*p;
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->height=1;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}


int nheight(struct Node * p)
{
    int x, y;
    if(p)
    {
        x = nheight(p->lchild);
        y = nheight(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }

    return 0;
}  //height

int NodeHeight(struct Node * p)
{
    int hl , hr;
    hl = (p && p->lchild)?p->lchild->height:0;
    hr = (p && p->rchild)?p->rchild->height:0;

    return hl>hr ? hl+1 : hr+1;
}

int balanceFactor(struct Node * p)
{
    int hl , hr;
    hl = (p && p->lchild)?p->lchild->height:0;
    hr = (p && p->rchild)?p->rchild->height:0;

    return hl - hr;

}



struct Node * LLRotate(struct Node * p)
{
/*
             p           pl
           /   \       /    \
         pl           q      p
        /  \                /
       q   plr            plr
*/

    struct Node * pl = p->lchild;
    struct Node *plr = p->lchild->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;
}


struct Node * LRRotate(struct Node * p)
{
/*
         p               plr
       /   \          /     \ 
     pl     r        pl       p  
   /    \           /  \   /  \
  l     plr        l  lrl lrr  r
       /   \ 
     lrl   lrr
*/

    struct Node * pl = p->lchild;
    struct Node *plr = p->lchild->rchild;

    plr->rchild = p;
    plr->lchild = pl;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    p->height = NodeHeight(p);
    //no need to reset pl->height since it wasn't moved

    if (root == p)
        root = plr;
        
    return plr;
}


struct Node * RRRotate(struct Node * p)
{
    /*
             p               pr
           /   \           /    \
                pr        p     prr
               /  \        \
             prl  prr      prl       
*/

    struct Node * pr = p->rchild;
    struct Node * prl = p->rchild->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    

    if(root == p)
        root = pr;

    return pr;

}

struct Node * RLRotate(struct Node * p)
{
/*
         p               prl
       /   \           /     \ 
     l      pr        p       pr  
          /    \     /  \    /  \
         prl   r    l   rrl rrr  r
        /   \ 
      rrl   rrr
*/

    struct Node * pr = p->rchild;
    struct Node * prl = p->rchild->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->lchild = p;
    pr->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

    return prl;
}



struct Node * RInsert(struct Node* p, int key)
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
        t->height = 1; // abdul uses 1 not zero
        t->lchild = NULL;
        t->rchild = NULL;
       return t;
              
    }
            
    if(key < p->data)
    {
        p->lchild = RInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        
        p->rchild = RInsert(p->rchild, key);
    }
    else if(key == p->data)
    {
        return p;
    }

    p->height = NodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
        return LLRotate(p);
    else if (balanceFactor(p)==2 && balanceFactor(p->lchild) == -1)
        return LRRotate(p);
    else if (balanceFactor(p)==-2 && balanceFactor(p->rchild) == -1)
        return RRRotate(p);
    else if (balanceFactor(p)==-2 && balanceFactor(p->rchild) == 1)
        return RLRotate(p);





    //return p;  
}

void inorder(struct Node * p){
    if (p){
        
        inorder(p->lchild);
        printf("%d, ", p->data) ;
        inorder(p->rchild);
    }
}


struct Node * Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
    else if(key<t->data)
        t=t->lchild;
    else
        t=t->rchild;
    }
    return NULL;
}


int main()
{
    struct Node *temp;
    root = RInsert(root, 30);
    RInsert(root,50);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,10);
    RInsert(root,42);
    RInsert(root,46);
    
    inorder(root);
    
    printf("\n");temp=Search(2);
    if(temp!=NULL)
        printf("element %d is found\n",temp->data);
    else
        printf("element is not found\n");
    return 0;
}
//code for doubly linked list
//abdulDoubleLinkList.c


#include <stdio.h>
#include <stdlib.h>


struct Node{
    struct Node * prev;
    int data;
    struct Node *next;
}*first=NULL;
//the above is a way to create a global Node struct called "first"


void create(int A[], int n)
{
    struct Node * t, *last;
    int i;

    //create the first node
    first=(struct Node *) malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i<n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    
}

void display(struct Node * p)
{
    while (p != NULL)
    {
        printf("%d, ",p->data);
        p = p->next;
    }

}

int length(struct Node * p)
{
    //one flaw is if p is not first or head node.
    
    int c = 0;
    while (p)
    {
        c++;
        p=p->next;
    }
    return c;
    //O(n)
    //could also make this recursive
}


void Insert(struct Node * p, int index, int x)
{
    struct Node * t;
    int i;
    if(p==NULL || index > length(p))
    {
        //there is no list or the requested insert postion is beyond the current list
        //one flaw here is if p is not the first or head node the returned length will be incorrect
        return;
    }
    //ok now we need t
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index==0)
    {
        first->prev = t;
        t->prev = NULL;
        t->next = first;
        first = t;
    }
    else
    {
        //will insert anywhere in a linked list but after a given position
        for(i=1; i<index-1;i++)
            p=p->next;
        t->next=p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;  //if p is NOT last node ok to set this.
        p->next= t;
    }

    return;
}  //Insert




int main()
{
    int A[]={2,4,6,8,10};
    create(A, 5);
    display(first);
    printf("\nLength of list: %d\n",length(first));





    return 0;
}
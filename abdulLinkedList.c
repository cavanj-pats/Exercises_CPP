//abdulLinkedList.c
//2024-12-04 JGC

#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*first=NULL, *last=NULL;
//the above is a way to create a global Node struct called "first"

void create(int A[], int n){
    int i;
    struct Node *t;
    //temp node and 

    first = (struct Node *) malloc(sizeof(struct Node));
    last = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;   //we can change later as we complete the list
   // last = first;
   

    for(i=1 ;i<n; i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));   //have to create a new memory address for each element
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
        if (i==1)
            first->next = t;
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

void displayR(struct Node * p)
{
    //recursive Display
    if(p != NULL)
    {
       // printf("%d ,", p->data);  //place print here will print in order.
        displayR(p->next);
        printf("%d ,", p->data);  //print after recursive call will reverse the list
    }
}

int count(struct Node * p)
{
    int c = 0;
    while (p!=0)
    {
        c++;
        p=p->next;
    }
    return c;
    //O(n)
    //could also make this recursive
}

int Rcount(struct Node *p)
{
    if (p!=0)
    {
        return Rcount(p->next)+1;
    }

    return 0;
}

int sum(struct Node *p)
{
    int s = 0;
    while (p)
    {
        s+=p->data;
        p = p->next;
    }

    return s;
}

int Rsum(struct Node *p)
{
    if (p)
    return p->data + Rsum(p->next);

    return 0;
}

int max(struct Node *p)
{
    int m = -65536;
    while (p)
    {
        if (m<p->data)
            m=p->data;

        p = p->next;
    }
    return m;
}

int Rmax(struct Node *p)
{
    int x;
    //recursive max
    if(!p)
        return -65536;
    
    x=Rmax(p->next);

    return x>p->data? x : p->data;

}

struct Node * LSearch(struct Node * p, int key)
{
 //also move the found item to first so next search will be faster
    struct Node * q;
    while (p!=NULL)
    {
        if(p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q=p;
        p=p->next;
    }

    return NULL;
}

struct Node * RSearch(struct Node * p, int key)
{
    //recursive search
    if (!p)
        return NULL;

    if (p->data == key)
        return p;

    return RSearch(p->next, key);
}



void Insert(struct Node * p, int index, int x)
{
    struct Node * t;
    int i;
    if(p==NULL || index > count(p))
    {
        //there is no list or the requested insert postion is beyond the current list
        return;
    }
    //ok now we need t
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;

    if(index==0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        //will insert anywhere in a linked list but after a given position
        for(i=1; i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next = t;
    }

    return;
}

void SortedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
 
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
        }
        q->next=t;
    }
}

int Delete(struct Node *p, int index)
{
    //remove the node by using its index and return the deleted node's data
    //first check for valid index
    int x = -1;
    struct Node * q = NULL;

    if (p && index > 0)
    {
        
        if(index == 1)
            {
                x = p->data;
                first = p->next;
                free(p);
                
             }
        else 
        {
            for(int i = 0; i<index-1 && p;i++)    //see the confimation that p is valid not null
            {
                q = p;
                p=p->next;
            }
            q->next = p->next;   //links node before deleted node to node after 
            x = p->data;
            free(p);
        
        }
        return x;
    }
    return -1;
}

int isSorted(struct Node * p)
{
    while(p->next)
    {
        if(p->data>p->next->data)
            return -1;
        
        p = p->next;
    }
    return 0;
}


int main()
{
   
    int A[]={3,5,9,11,15};
    struct Node * temp;

    create(A, 5);
    display(first);
    printf("\n");
    displayR(first);
    printf("\n");
    //SortedInsert(first, 16);
    //display(first);
    /*
    printf("count is: %d\n", count(first));
    printf("Rcount is: %d \n", Rcount(first));
    printf("Sum is: %d\n",sum(first));
    printf("RSum is: %d\n",Rsum(first));
    printf("Max Element is: %d\n", max(first));
    printf("RMax Element is: %d\n", Rmax(first));

    
    
    temp = LSearch(first,7);
    if (temp)
        printf("Key found.\n");
    else    
        printf("Key not found.\n");
*/
  //  display(first);
  //  printf("\n");
   // struct Node * t;
   //SortedInsert(first,18);
   display(first);
   printf("\nIsSorted: %d\n",isSorted(first));

    


    return 0;
}
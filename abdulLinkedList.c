//abdulLinkedList.c
//2024-12-04 JGC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cstack.h"  //home made stack in C
//#include "iostream.h"


struct Node{
    int data;
    struct Node *next;
}*first=NULL, *last=NULL, *second=NULL, *third=NULL;
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
} //create


//create2 allows for a program that has to LLists  one at first the other at second.
//second list is created below.
void create2(int A[], int n){
    int i;
    struct Node *t;
    //temp node and 

    second = (struct Node *) malloc(sizeof(struct Node));
    last = (struct Node *) malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;   //we can change later as we complete the list
   // last = first;
   

    for(i=1 ;i<n; i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));   //have to create a new memory address for each element
        t->data = A[i];
        t->next = NULL;
        last->next=t;
        last = t;
        if (i==1)
            second->next = t;
    }
}//create2

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
    if(!p || (index < 1 || index > count(p)))
        return -1;
    if (index == 1)
    {
        x = p->data;
        first = p->next;
        free(p);
        return x;
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
        return x;
    }        
}


int isSorted(struct Node * p)
{
    //if there are duplicates adjacent to each other they should be ignored.
    
    while(p->next)
    {
        if(p->data>p->next->data)
            return -1;
        
        p = p->next;
    }
    return 0;
}

void RemoveDuplicates(struct Node * p)
{
    //list must be sorted
    struct Node *q = p->next;

    while (q!=NULL)
    {
        if(p->data != q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q=p->next;
        }
    }
}

void ReversList(struct Node * p)
{
    struct Node* q=NULL, *r=NULL;
    while (p != NULL)
    {
        //slide along the list
        r= q;
        q = p;
        p = p->next;
        //reverse by making this assignment
        q->next = r;
    }
    first = q;  

}

void ReverseListRec(struct Node * q, struct Node * p)
{
    //reverse list using recursion

    if(p!=NULL)
    {
        ReverseListRec(p, p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void Concat(struct Node * p, struct Node * q)
{
    //add q onto the end of p and make it the third list
    //move to last node of p and have it point to first node of q which is second
    third = p;

    while (p->next !=NULL)
    {
        p = p->next;
    }
    p->next = q;
    //i think this also changes "first" LList.
}

void Merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    //establish the first node of the merged list "third"
    if(p->data < q->data)
    {
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        third->next=NULL;
    }

    //loop through the list and take the smaller value
    //until we get to the end of one of the lists
    while(p && q)
    {
        if(p->data < q->data)
            {
                last->next=p;
                last=p;
                p=p->next;
                last->next=NULL;
            }
            else
            {
                last->next=q;
                last=q;
                q=q->next;
                last->next=NULL;
        }
    }
    //one list is at the end.  all that needs to be done is connect last node to first node
    //or remainining list.
    if(p)last->next=p;  
    if(q)last->next=q;

}

int IsLoop(struct Node * f)
{
    struct Node *p, *q;
    p = q = f;
    
    do
    {
        p=p->next;
        q=q->next;
        //now conditionally move q
        q = q?q->next:q;  //if q is not null move it, if it is null leave it alone
    } while(p && q && p!=q);
    if(p==q) 
        return 1;
    else
        return 0;
}

int findMiddleNode(struct Node *p)
{
    struct Node *q;
    q = p;
    //traverse the list using p at twice the speed of q
    //once the end is reached q will be in the middle
    while(p)
    {
        p = p->next;
        if(p) 
            p=p->next;
        if (p) 
            q = q->next;
    }
    return q->data;
} //findMiddleNode  traverse two pointers one at double speed

int findMiddleNode1(struct Node* p)
{
    int i;
    int mid = (int) ceil(count(p)/2);
    for(i=0; i<mid;i++)
        p=p->next;

    return p->data;
}  //findMiddleNode1


int findMiddleNode3(struct Node* p){
    struct Stack  *s;
    initStack(s);

    int length = 0;
    int v =0;
    while (p){
        push(s, p->data);
        length++;
        p = p->next;
    }
    
    int popLength = (int)((length/2.0));   //(int)floor(length/2.0))
    while (popLength){
        v = pop(s);
        popLength--;
    }
    //printf("Middle Element (Method-III): %d", peek(s));
    v = peek(s);
    return v;

}//middleNode3


//from the quiz
void rearrange (struct Node *list)
{

    struct Node *p, *q;
    int temp;
    if (!list || !list -> next) return;
    p = list;
    q = list -> next;

    while (q)
    {
        temp = p-> data;
        p -> data = q -> data;
        q -> data = temp;
        p = q ->next;
        q = p ? p -> next : 0;
    }

}//rearrange from quiz

int main()
{
   
    int A[]={3,5,9,11,15};
    int B[]={20,30,40,50,60};
   //for testing remove duplicates
   //int A[]={3,3,5,8,8};
    struct Node * temp;

    create(A, 5);
    create2(B,5);

    printf("Display First:\n");
    display(first);
    printf("\nDisplay Second:\n");
    display(second);
//rearrange is from the quiz
    //rearrange(first);
   // printf("\nAfter Rearrange: \n");
    //display(first);
   // 
    printf("\nFind MIddle List A: %d\n",findMiddleNode(first));
    printf("\nFind Middle List A 1: %d\n",findMiddleNode1(first));
    printf("\nFind MIiddle List A 3: %d\n", findMiddleNode3(first));
    printf("\nFind Middle List B: %d\n", findMiddleNode(second));
    
    printf("\nDisplay Reversed:\n");
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
   
   /*
   //testing isSorted and Delete
   display(first);
   printf("\nIsSorted: %d\n",isSorted(first));
    Delete(first,5);
    display(first);
    */

    //testing Remove Duplicates
    RemoveDuplicates(first);
    printf("Remove Duplicates:\n");
    display(first);

    //reverse list
    
    ReverseListRec(NULL,first);
    printf("\nReverse List:\n");
    display(first);


    //test IsLoop
    struct Node * t1 = first->next->next;   //second node
    struct Node * t2 = first->next->next->next->next;  //fifth node
    //t2->next = t1;   // forms a loop

    printf("\nIsLoop:\n");
    printf("%d\n",IsLoop(first));
    

    return 0;
}
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
    //if index = 0 node will become first
    //if index is any other value less than length the new node will be inserted after node at index

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
        for(i=0; i<index-1;i++)  //start at zero and traverse links not nodes I guess....
            p=p->next;
        t->next=p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;  //if p is NOT last node ok to set this.
        p->next= t;
    }

    return;
}  //Insert

int Delete(struct Node *p, int index)
{
   
    
    //int data = p->data;   //don't do this.  If p is null there would be an error instead
    int data = -1;   //some dummy variable. Don't assign it a value until you know Node is not null
    int i;
    if(index<1 || index>length(p))
        return -1;

    if(index ==1)
    {
        first = first->next;  //i was using p->next but what if P is not first. it should be but...
        
        if(first)   first->prev = NULL;  //first exists so we can set its previous
        data = p->data; //abdul seems to assume, like I did, that p == first.
        free(p);  //free the memory p was in
        return data;
    }
    else
    {
        //starting the index at 0 might be preferred because if first node
        //then loop wont run at all.  
        for (i=0;i<index-1;i++)   //start at 0 as i want to land at the node at index
            p=p->next;
        if(p->next)
            p->next->prev = p->prev;    
        p->prev->next = p->next;   //is fine even if p->next is null
        data = p->data;
        free(p);
        return data;
    }

    
} //delete

void Reverse(struct Node *p)
{
    struct Node *temp;
    p = first;  //just to make sure I guess. 
    while(p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;
        p=p->prev;  //because interchanged pointers need to move to previous
        if(p!=NULL && p->next == NULL ) first = p;  //this should be at the end of the list that will now be first
    }

}//Delete



int main()
{
    int A[]={2,4,6,8,10};
    create(A, 5);
    display(first);
    printf("\nLength of list: %d\n",length(first));

    //Insert(first,1,11);
    //display(first);
    //printf("\nLength of list: %d\n",length(first));

   // printf("Deleted Node: %d\n",Delete(first,3));
    Reverse(first);
    printf("After Reverse: ");
    display(first);


    return 0;
}
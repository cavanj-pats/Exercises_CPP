//Circular Doubly Linked List
//abdulLListCircDbl.c
//



#include <stdio.h>
#include <stdlib.h>


struct Node{
    struct Node * prev;
    int data;
    struct Node *next;
}*head=NULL, *tail=NULL;
//the above is a way to create a global Node struct called "first"


void create(int A[], int n){
    int i;
    struct Node *t;
    struct Node *q;
    //temp node and 

    head = (struct Node *) malloc(sizeof(struct Node));
    q = (struct Node *) malloc(sizeof(struct Node));
    
    head->data = A[0];
    head->prev = head;
    head->next = head;   //we can change later as we complete the list
    q = head;
   

    for(i=1 ;i<n; i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));   //have to create a new memory address for each element
        t->data = A[i];
        t->prev = q;
        t->next = head;
        q->next=t;
        head->prev= t;
        q=t;
        //ever new Node must be connected to head.  head->prev and t->next
        
    }
} //create

void display(struct Node *p)
{
    //trying to write the code in case p comes at the middle of the list
    //create a traversing node q
    //struct Node * q = (struct Node *) malloc(sizeof(struct Node));

    //actually regardless of where p is, we will force it to be head

    //display a circular doubly linked list
    if (p)
    {
        p = head;
     
        do{
            printf("%d, ",p->data);
            p = p->next;
        }while (p && p !=head);   //there really should be no null Nodes
        printf("\n"); //print a newline
    }

}//display

int length(struct Node * p)
{
    //one flaw is if p is not first or head node.
    
    int c = 0;
    if(p){
        p = head;
    
        do
        {
            c++;
            p=p->next;
        }while (p!=head);
        return c;
    }
    return 0;  //safe to return 0 nodes if p is null
} //length



//insert a Node at index containing data x
void Insert(struct Node * p, int index, int x)
{
    struct Node * t;
    int i;
    
    if(index > length(p) || index < 0)
    {
        //there is no list or the requested insert postion is beyond the current list
        return;
    }
    

    //ok now we need t
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    
    
    if(index==0)
    {
        //check and see if LList is empty
        if(head == NULL)
        {
            //there are no nodes so this is the first node
            head = t;
            head->next = head;
            head->prev = head;
            //tail = head;
            //return;
        }
        else
        {
            // move to head. 
            while(p!=head) 
                p = p->next;   //move to head and insert before head

            p->prev->next = t;  //connect the last node with what will be the new head node
            t->prev = p->prev;
            t->next = p;
            p->prev = t;
            head = t;          
        }
    }
    else
    {
        //will insert anywhere in a linked list but after a given position
        for(i=0; i<index-1;i++)
            p=p->next;
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }

    return;
}//Insert


// Delete from Circular Doubly Linked List
int Delete(struct Node *p, int index)
{
    int x = -1;//intial value for the return variable
    int i;

    if(index <1 || index >length(p))
        return x;  //index is out of range

    if(index == 1)
    {
        //need to delete the head node and re-assign it
        p=head;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x = p->data;
        head = p->next;
        free(p);
        return x;

    }
    else
    {
        for (i=1; i<index; i++)
            p=p->next;
        
        if(p)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            x = p->data;
            free(p);
            return x;
        }
    }
    
    return -1;   //no node to delete
}





int main()
{
    int A[]={2,4,6,8,10};
    create(A, 5);
    display(head);
    printf("\nLength of list: %d\n",length(head));

    Insert(head,1,11);
    display(head);
    printf("\nLength of list: %d\n",length(head));

    printf("Deleted Node: %d \n", Delete(head,6));
    display(head);
    printf("\nLength of list after remove node: %d\n",length(head));
    //Reverse(first);
    //printf("After Reverse: ");
    //display(first);


    return 0;
}
//circular Linked list
//abdulLinkedListCircular.c

#include <stdio.h>
#include <stdlib.h>
 
//in a circular linked list there is a head node.
struct Node{
    int data;
    struct Node *next;
}*head=NULL;
//the above is a way to create a global Node struct called "first"

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    //temp node and 

    head = (struct Node *) malloc(sizeof(struct Node));
    last = (struct Node *) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = head;   //we can change later as we complete the list
    last = head;
   

    for(i=1 ;i<n; i++)
    {
        t=(struct Node *) malloc(sizeof(struct Node));   //have to create a new memory address for each element
        t->data = A[i];
        t->next = last->next;
        last->next=t;
        last = t;
        
    }
} //create

/*
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
*/

void display(struct Node * p)
{
    do
    {
        printf("%d, ",p->data);
        p = p->next;
    } while (p != head);
    printf("\n");

}

void Rdisplay(struct Node * h)
{
    static int flag = 0 ;  //first time in h will equal head
    if (h!=head || flag ==0)
    {
        flag = 1;
        printf("%d, ",h->data);
        Rdisplay(h->next);
    }
    flag = 0;
    if (h==head && flag ==0)
        printf("\n");  //just print a newline
}



int main()
{
    int A[]={2,4,6,8,10};
    create(A,5);
    Rdisplay(head);
    display(head);


    return 0;
}
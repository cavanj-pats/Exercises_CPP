//circular queue array based.
//don't implement non circular since it is inefficient
//abdulQueueArrayCircular.c

//queues - add items to rear and remove from the front. like a line

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL, *rear=NULL;
//the above is a way to create a global Node struct called "first"



void create(struct Node * q)
{
    
}

int isEmpty(struct Node * q)
{
    if (front = NULL)
        return 1;
    else    
        return 0;
}




void enqueue(struct Node * q, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue Space is Full!\n");
    else 
    {   
        if(front == NULL)
        {
            //first element
            t->data = x;
            t->next = NULL;
            front = rear = t;
        }
        else
        {
            t->data = x;
            t->next = NULL;
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(struct Node * q)
{
    //always deque from front
    int x = -1;
    if (front == NULL)
        printf("Queue is empty!\n");
    else
    {
        x = front->data;
        front = front->next;
    }
    
    return x;
}

void display()
{
    struct Node *t;
    t = front;
    if (t!=NULL)
    {
        do
        {
           printf("%d, ",t->data);
           t = t->next;
        } while (t);
        printf("\n");
    }
    
}

int main()
{
    struct Node * q;
    //create(q, 10);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);

    display();

    printf("Dequeue: %d\n",dequeue(q));
    printf("Dequeue: %d\n",dequeue(q));
    display();

    return 0;


}
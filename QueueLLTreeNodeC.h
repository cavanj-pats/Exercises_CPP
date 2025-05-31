//circular queue array based.
//don't implement non circular since it is inefficient
//abdulQueueArrayCircular.c
//QueueLLTreeNodeC.h

//queues - add items to rear and remove from the front. like a line

/*
                *******This Structure does not define a struct Queue. Only a struct Node and functions  *******
*/

#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
//#include <inttypes.h>

struct Node{
    struct Node *left;
    int data;
    struct Node *right;
    struct Node *next;
}*front = NULL, *rear = NULL;
//the above is a way to create a global Node struct called "first"

/*
struct Queue
{
    struct Node **Q;
   // struct Node *front;
    //struct Node *rear;
};
*/


/*
void create()
{
   
       
}
*/

int isEmpty()
{
    if (front == NULL)
        return 1;
    else    
        return 0;
}




void enqueue(struct Node * t, int x)
{
    //struct Node *t;
    //t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Queue Space is Full!\n");
    else 
    {   
        if(front == NULL)
        {
            //first element
            t->data = x;
            t->next = NULL;
            t->left = NULL;
            t->right = NULL;
            front = rear =  t;
              
        }
        else
        {
            t->data = x;
            t->next = NULL;
            t->left = NULL;
            t->right = NULL;
            rear->next = t;
            rear = t;
        }
    }
}

struct Node * dequeue()
{
    //always deque from front
   struct  Node * x;
    if (front == NULL)
        //printf("Queue is empty!\n");
        x = NULL;   // when creating a tree there are times when the queue will be empty
    else
    {
        x = front;
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


/*
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

*/
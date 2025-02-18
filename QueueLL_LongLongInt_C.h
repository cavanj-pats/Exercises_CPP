//circular queue array based.
//don't implement non circular since it is inefficient

//QueueLL_LongLongInt_C.h

//queues - add items to rear and remove from the front. like a line

#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
//#include <inttypes.h>

struct queueNode{
    //struct Node *left;
    long long int data;
    //struct Node *right;
    struct queueNode *next;
};  //*front = NULL, *rear = NULL;
//the above is a way to create a global Node struct called "first"


struct Queue
{
    struct queueNode *front;
    struct queueNode *rear;
   
};




void createQueue(struct Queue * q)
{
   q->front = (queueNode *)malloc(sizeof(queueNode));
   q->front = NULL;

   q->rear = (queueNode *)malloc(sizeof(queueNode));
   q->rear = NULL;
       
}


int isEmpty(struct Queue *q)
{
    if (q->front == NULL)
        return 1;
    else    
        return 0;
}




void enqueue(struct Queue *q, long long int x)
{
    struct queueNode *t;
    t = (struct queueNode *)malloc(sizeof(struct queueNode));
    if(t == NULL)
        printf("Queue Space is Full!\n");
    else 
    {   
        if(q->front == NULL)
        {
            //first element
            t->data = x;
            t->next = NULL;
            
            q->front = q->rear =  t;
              
        }
        else
        {
            t->data = x;
            t->next = NULL;
            
            q->rear->next = t;
            q->rear = t;
        }
    }
}

struct queueNode * dequeue(struct Queue *q)
{
    //always deque from front
   struct  queueNode * x;
    if (q->front == NULL)
        //printf("Queue is empty!\n");
        x = NULL;   // when creating a tree there are times when the queue will be empty
    else
    {
        x = q->front;
        q->front = q->front->next;
    }
    
    return x;
}

void display(struct Queue q)
{
    struct queueNode *t;
    t = q.front;
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
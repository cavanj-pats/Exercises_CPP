//circular queue array based.
//don't implement non circular since it is inefficient
//abdulQueueArrayCircular.c

//queues - add items to rear and remove from the front. like a line

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;   //size of teh queue used to size array
    int front;  //"pointer" to front element in list
    int rear; //pointer to rear elment of list
    int * Q;  //hello
};

void create(struct queue * q, int size)
{
    q->size = size;
    q->Q = (int *) malloc(size * sizeof(int));
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct queue * q)
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}




void enqueue(struct queue * q, int x)
{
    if((q->rear + 1) % q->size == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = (q->rear + 1)%q->size;
        q->Q[q->rear] = x;
    }
   

}

int dequeue(struct queue * q)
{
    //always deque from front
    int x = -1;
    if (q->front == q->rear)
        printf("Queue is empty!\n");
    else
    {
        q->front = (q->front + 1)%q->size;
        x = q->Q[q->front];
    }
    
    return x;
}

void display(struct queue q)
{
    //don't want to modify the data
    //int x = (q.front + 1)%q.size;  //the value of q.front is managed by dequeue and enqueue.
                                    //repeat the modular arithmetic here.
    int x = q.front + 1;  //q.front will have no value.
    do
    {
        printf("%d", q.Q[x]);
        x = (x+1)%q.size;
    } while (x != (q.rear + 1)%q.size);  //I had q.front not q.rear originally.  got bad data on PC.
    printf("\n");
    
}

int main()
{
    struct queue * q;
    create(q, 10);
    enqueue(q,4);
    enqueue(q,5);
    enqueue(q,6);

    display(*q);

    printf("Dequeue: %d\n",dequeue(q));

    display(*q);

    return 0;


}
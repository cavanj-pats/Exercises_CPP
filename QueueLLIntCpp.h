//abdul Queue using LList
//QueueLLIntCpp.h  Jim Cavanaugh  2/15/2025
//C++ header file for a Queue based on a LinkedList to hold Integer Nodes

#include <iostream>


using namespace std;

class Node
{
    public:
    int data;
    Node * next;
};

class Queue
{
    private:
        Node * front;
        Node * back;

    public:
        Queue();
        ~Queue();
        void enqueue(int x);
        int dequeue();
        bool isEmpty();
        void display();

};


Queue::Queue()
{
    front = nullptr;
    back = nullptr;
}

Queue::~Queue()
{
    Node* p = front;
    while (front){
        front = front->next;
        delete p;
        p = front;
    }
}

bool Queue::isEmpty()
{
    if (front == nullptr)
        return true;
    else
        return false;
}

void Queue::enqueue(int x)
{
    Node * t = new Node;  //if t is nullptr then heap is full
    if (t == nullptr)
        {
            cout << "Queue is Full/Overflow" << endl;
        }
    else
    {
        t->data = x;
        t->next = nullptr;
        if(front == nullptr)
        {
            //first node
            front = t;
            back = t;
        }
        else{
            back->next = t;
            back = t;
        }
    }

}

int Queue::dequeue()
{
    int x = -1;
    Node *p ;
    if(isEmpty())
        cout << "Queue is empty!" << endl;
    else
    {
        x = front->data;
        p=front;
        front = front->next;
        delete p;
    }

    return x;

}

void Queue::display() {
    Node* p = front;
    while (p){
        cout << p->data << flush;
        p = p->next;
        if (p != nullptr){
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

/*
int main()
{
    Queue q;
   q.dequeue();
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(11);

    q.display();

    printf("Dequeue: %d\n",q.dequeue());
    printf("Dequeue: %d\n",q.dequeue());
    q.display();

    return 0;


}
    */
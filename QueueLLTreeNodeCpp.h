//abdul Queue using LList
//QueueLLIntCpp.h  Jim Cavanaugh  2/15/2025
//C++ header file for a Queue based on a LinkedList to hold Integer Nodes
/*  ***attempting to use the link list variant to make a queue of nodes where each node is a tree node
 */


#include <iostream>


using namespace std;



class Node
{
    public:
    int data;
    Node * next;
    Node * left;
    Node * right;
    Node();
};

Node::Node()
{
    data = -1;
    next = nullptr;
    left = nullptr;
    right = nullptr;
}

class Queue
{
    private:
        Node * front;
        Node * back;

    public:
        Queue();
        ~Queue();
        void enqueue(Node * x);
        Node * dequeue();
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

void Queue::enqueue(Node * t)
{
    //Node * t = new Node;  //if t is nullptr then heap is full
    if (t == nullptr)
        {
            cout << "Queue is Full/Overflow" << endl;
        }
    else
    {
       // t->data = x;
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

Node * Queue::dequeue()
{
    Node * x ;
    //Node *p ;
    if(isEmpty())
        cout << "Queue is empty!" << endl;
    else
    {
        //x = (front->data);
        //p=front;
        x = front;
        front = front->next;
        //delete p;
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



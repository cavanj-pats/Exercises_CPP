//Binary Tree Creation
//abdulBinaryTreeCpp.cpp

//jim cavanaugh

#include <iostream>
#include "QueueLLTreeNodeCpp.h"


using namespace std;

Node *root = new Node;

void createTree()
{
    Node *p, *t;
    int x;
    Queue q;

    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->left = nullptr;
    root->right = nullptr;
    q.enqueue(root);

    while (!q.isEmpty() )
    {
        p = q.dequeue();


        cout << "Enter left child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->left = t;
            q.enqueue(t);

        }

        cout << "Enter right child value of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->left = nullptr;
            t->right = nullptr;
            p->right = t;
            q.enqueue(t);

        }
        
    }
}

void preorder(Node * p){
    if (p){
        cout << p->data << ", " << flush;
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(Node * p){
    if (p){
        
        inorder(p->left);
        cout << p->data << ", " << flush;
        inorder(p->right);
    }
}
 
void postorder(Node *p)
{
    if(p)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << ", "<<  flush;
    }
}




int main() {
 
    createTree();
 
    preorder(root);
    cout << endl;
    
    inorder(root);
    cout << endl;
    
    postorder(root);
    cout << endl;
 
    return 0;
}
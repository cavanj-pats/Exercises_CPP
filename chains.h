//chains.h
//header type file for Hash Table collision avoidance Chaining technique

//3/23/2025  Jim Cavanaugh

#ifndef CHAINS_H
#define CHAINS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



//copy abdulLinkedList.c code here



struct Node{
    int data;
    struct Node *next;
}*first=NULL;
//the above is a way to create a global Node struct called "first"



int count(struct Node * p)
{
    int c = 0;
    while (p!=0)
    {
        c++;
        p=p->next;
    }
    return c;
    //O(n)
    //could also make this recursive
}

//rename SortedInsert to insertSorted
// need to use double pointer because the has table will be filled with pointers to pointers
void insertSorted(struct Node **H,int x)
{
    struct Node *t,*q=NULL, *p=*H;
 
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL)
    {
        first=t;  //first is referred to later as is *H  seems redundant
        *H=t;
    }  
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
        }
        q->next=t;
    }
}

//using recursive search
struct Node *Search(struct Node *p, int key)
{
    //recursive search

    //note: i believe condition can be added: p->data>key becauase we are using a sorted list
    if (!p)
        return NULL;

    if (p->data == key)
        return p;

    return Search(p->next, key);
}

void deleteKey(struct Node *p, int key)
{
    struct Node *temp = NULL;
    temp = Search(p,key);
    
    if (!temp)  return;   //key not found.  Tell user??

    struct Node *q;
    

    while(p)
    {
        if(p->data == key)
        {
            if(p==first)
            {
                first = p->next;
                free(p);
                return;
            }
            else
            {
                q->next = p->next;
                free(p);
                return;
            }

        }
        else
        {
            //move to the next node and keep a trailing pointer q
            q = p;
            p = p->next;
        }

    }  //end while
    
    return;  //really shouldn't ever get here

}

int Delete(struct Node *p, int index)
{
    //remove the node by using its index and return the deleted node's data
    //first check for valid index
    int x = -1;
    struct Node * q = NULL;
    if(!p || (index < 1 || index > count(p)))
        return -1;
    if (index == 1)
    {
        x = p->data;
        first = p->next;
        free(p);
        return x;
    }
    else 
    {
        for(int i = 0; i<index-1 && p;i++)    //see the confimation that p is valid not null
        {
            q = p;  
            p=p->next;
        }
        q->next = p->next;   //links node before deleted node to node after 
        x = p->data;
        free(p);
        return x;
    }        
}

#endif
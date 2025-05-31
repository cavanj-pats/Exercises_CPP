//hash table chaining technique for collision resolution
//abdulChaining.c

#include<stdio.h>
#include "chains.h"
/*

*********************  Working on DELETE just added indexFind and DeleteHash as a way to 
get back to using the native link list code with the workign delete function

*/

int hash(int key)
{
    return key%10 ;   //hash function
}

void InsertHash(struct Node *H[], int key)
{
    int index=hash(key);
    insertSorted(&H[index],key);
}

//i think i need tp us the delete function here.
void deleteHash(struct Node *H[], int key)
{
    int index = hash(key);
    deleteKey(H[index],key);  //in chains.h customized delete function
    H[index] = first;  //  re-assign the head node of the list just in case Key deleted the head node
}

int main()
{
    struct Node *HT[10];  //hash table
    int key;
    struct Node *temp=NULL;

    int i;

    for(i=0; i<10;i++)
        HT[i]=NULL;

    InsertHash(HT, 12);
    InsertHash(HT, 22);
    InsertHash(HT, 42);

    

    key = 12;
    // temp = Search(HT[hash(key)], key);

    // if(!temp)
    //     printf("%d key not found. \n", key);
    // else
    //     printf("Key %d found!\n", temp->data);

    //delete key 22
    deleteHash(HT, key);
    //printf ("%d is at index: %d (-1) for not found.\n",key,indexFind(HT[hash(key)], key));
    InsertHash(HT, 12);

    return 0;
}
//hash table chaining technique for collision resolution
//abdulChaining.c

#include<stdio.h>
#include "chains.h"


int hash(int key)
{
    return key%10 ;   //hash function
}

void InsertHash(struct Node *H[], int key)
{
    int index=hash(key);
    insertSorted(&H[index],key);
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

    

    key = 22;
    // temp = Search(HT[hash(key)], key);

    // if(!temp)
    //     printf("%d key not found. \n", key);
    // else
    //     printf("Key %d found!\n", temp->data);

    //delete key 22
    deleteKey(HT[hash(key)], key);


    return 0;
}
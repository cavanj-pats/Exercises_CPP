//array ADT
//structure
//abdul ArrayADTstruct.cpp


#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void arrDisplay(Array arr)
{
    for (int i=0; i<arr.length; i++)
    {
        printf("%d, ",arr.A[i]);
    }
    printf("\n");
}

void arrAppend(Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void arrInsert(Array *arr, int idx, int x)
{
    //probably should check that arr->length < arr->size;

    if(idx > arr->length) return;

    for(int i = arr->length; i>idx; i--)
        arr->A[i] = arr->A[i-1];
    
    arr->A[idx] = x;
    arr->length++;

    return;
}

void arrDelete(Array *arr, int idx)
{
    //remove item at index idx

    //abduls function returned the value at that index
    //probably a good idea to check that you deleted the correct element
    //not sure how to undo it.....
    if(idx >=0 && idx < arr->length)
    {
        for(int i = idx; i<arr->length-1; i++)
            arr->A[i]= arr->A[i+1];
        
    
        arr->length--;
    }
    return;
}

int arrSearch(Array *arr, int value)
{
    int j = 0;
    int k = arr->length-1;

    while (j<=k)
    {
        if(arr->A[j] == value) return j;
        if(arr->A[k] == value) return k;
        j++;
        k--;

    }
    return -1;
}


int main()
{
    Array arr;
    arr.size = 10;

    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.A[0] = 2;
    arr.A[1] = 4;
    arr.A[2] = 6;
    arr.A[3] = 8;
    arr.length = 4;
    
    arrDisplay(arr);
    arrAppend(&arr, 11);
    arrDisplay(arr);
    arrInsert(&arr,0,99);
    arrDisplay(arr);
    arrDelete(&arr,0);
    arrDisplay(arr);
    if (!(arrSearch(&arr,10) == -1))
        printf("found\n");
    else
        printf("Not found\n");

    free(arr.A);

    return 0;

}
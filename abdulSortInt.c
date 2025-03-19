//sort techniques
//abdulSortInt.c
//3/19/2025

#include <stdio.h>



void swap(int *xp, int *yp){
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int A[], int n)
{
    //n is the number of elements
    //move the smallest forward and the largest to end of array
    int flag;

    for(int i = 0; i<n-1; i++)
    {
        flag = 0;
        for(int j = 0; j<n-1-i; j++)
        {
            if(A[j] >A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
            
        }
        if (flag == 0) break;
    }
}

void insertionSort(int A[], int n)
{
    int temp;
    //first element is sorted

    for (int i = 0; i<n-1; i++)
    {

        for(int j = )
    }
}

void display(int A[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ",A[i]);
    
    printf("\n");
}


int main()
{
    int A[]={8, 8, 7, 3, 2};
    int n = 5;

    display(A,n);
    bubbleSort(A, n);
    display(A,n);

    return 0;


    
}
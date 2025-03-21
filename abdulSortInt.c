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
    int temp, j;
    //first element is sorted

    for (int i = 1; i<n; i++)
    {
        j = i-1;
        temp = A[i];
        while(j > -1 && A[j]>temp)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = temp;
        
    }
}

void merge(int A[], int l, int mid, int h)
{
    int i = l;
    int j = mid+1;
    int k = l;
    int B[100];   //used B[h+1] did not work can also use B[100] which is plenty big enough.   B is the auxiliary array
    while(i<=mid && j <=h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];

    //copy B contents back to A
    for(i = l; i<=h; i++)
        A[i] = B[i];

}

void itMergeSort(int A[], int n)
{
    int p, l, h, mid ;
    //p is for passes

    for(p=2; p<=n; p=p*2)
    {
        for(int i=0; i+p-1<n; i=i+p)
        {
            l=i;   //crazy problem if i declare i at top of function and assign to 0 in for loop,  it got assigned 1 not zero.  I can't explain that.
            h=i+p-1;
            mid=(l+h)/2;
            merge(A,l,mid,h);

        }
    }
    if(p/2<n)
        merge(A,0,p/2-1,n);
}


void display(int A[], int n)
{
    for(int i = 0; i<n; i++)
        printf("%d ",A[i]);
    
    printf("\n");
}


int main()
{
    int A[]={8, 3, 7, 2, 9};
    int n = 5;

    display(A,n);
    //bubbleSort(A, n);
    itMergeSort(A, n);
    display(A,n);

    return 0;


    
}
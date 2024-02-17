//abdulArray01.c   abdul on Udemy's first Array demo.  In C.


#include <stdio.h>
#include <stdlib.h>    //I believe malloc resides here


struct Array
{
    int *A;     //element value
    int size;  //capacity of array
    int length; //number of elements in the array
};


void Print_Array(Array arr)
{
    printf("Array Elements Are:\n")
    {
        for(int i=0; i<arr.length; i++)
            printf("%d, ", arr.A[i]);
    }
    printf("\n");
    return;

}

int main()
{
    struct Array arr;
    int n;
    int i;
    printf("Program to create and Array from your entered data.\n");
    printf("Enter size of Array; ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size *sizeof(int));
    arr.length = 0;

    printf("Enter number of Elements: ");
    scanf("%d", &n);   //I guess you have to pass an address to scanf

    printf("Enter all the Elements:\n");
    for(i = 0; i<n; i++)
    {
        scanf("%d", &arr.A[i]);
        arr.length++;
    }    

    Print_Array(arr);


    free arr;
    return 0;


}
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

void swap(int *xp, int *yp){
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}
//Abdul's search included a swap process that used the above swap function
//it was thought repeated searches for the same item would speed up since the searched for item
//was closer to the start of the array.  
//for my function below, searching from both directions, it would speed it up but perhpas not as much.
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

//binary searches require a sorted array
int arrBinarySearch_it(Array arr,  int key)
{
    int l = 0;
    int h = arr.length-1;
    int mid;
    
    while (l <= h)
    {
        mid = (l+h)/2;
        if (arr.A[mid] == key) return mid;
        if (key > arr.A[mid])
        {
            l = mid+1;
        } else
        {
            h = mid-1;
        }
    }

    return -1;
}

int arrBinarySearch_rec(Array arr, int l, int h, int key)
{
    int mid;
    if (l <= h){
        mid = (l+h)/2;
        if (arr.A[mid] == key) return mid;

        if (key < arr.A[mid]){
            return arrBinarySearch_rec(arr,l,mid-1, key);
        } else
        {
            return arrBinarySearch_rec(arr, mid+1,h,key);
        }
    }
    return -1;
}

int get(Array arr, int x)
{
    if (x >= 0 && x < arr.length)
        return arr.A[x];

    return -1;
}

void set(Array *arr, int x, int val)
{
    if (x>= 0 && x<arr->length)
        arr->A[x]= val;
}

int max(Array arr)
{
    int max = 0;
    int j=0;
    int k = arr.length-1;
    while (j <= k)
    {
        if (arr.A[j] > max) max = arr.A[j];
        if (arr.A[k] > max) max = arr.A[k];
        j++;
        k--;
    }
    return max;
}  //max

int min(Array arr)
{
    int min = arr.A[0];
    int j = 1;
    int k = arr.length -1;
    while (j<=k)
    {
        if (arr.A[j] < min) min = arr.A[j];
        if (arr.A[k] < min) min = arr.A[k];
        j++;
        k--;
    }
    return min;
}

int arrSum(Array arr, int n)
{
    //NOTE:  n is the index.  What is sent is arr.length - 1.  if arr.length == 0 then
    // the result will be -1.  This is the situation we need to guard against.
    if (n < 0)
        return 0;
    else
        return arrSum(arr, n-1) + arr.A[n];

}//arrSum

float average(Array arr)
{
    if (arr.length>0)
    {
        return (float) arrSum(arr, arr.length-1) / (float) arr.length;
    }
    return 0.0;
}// average

void arrReverse(Array *arr)
{
    //uses swap function
    int i, j;
    for (i=0, j = arr->length-1; i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}  //arrReverse

//left shift
void leftShift(Array *arr)
{
    for (int i=1;i<arr->length;i++)
        arr->A[i-1]= arr->A[i];
    
    arr->A[arr->length-1] = 0;
} //left shift

//left rotate
void leftRotate(Array *arr)
{
    int temp = arr->A[0];
    for (int i=1;i<arr->length;i++)
        arr->A[i-1]= arr->A[i];
    
    arr->A[arr->length-1] = temp;
} //left rotate

//right shift
void rightShift(Array *arr)
{
    for(int i=arr->length-2; i>=0; i--)
    {
        arr->A[i+1]= arr->A[i];
    }
    arr->A[0]=0;
}
//right rotate
void rightRotate(Array *arr)
{
    int temp = arr->A[arr->length-1];
     for(int i=arr->length-2; i>=0; i--)
    {
        arr->A[i+1]= arr->A[i];
    }
    arr->A[0]=temp;

}  //rightRotate

bool isSorted(Array arr)
{
    for (int i = 0; i<arr.length-1; i++)
    {
        if (arr.A[i] >= arr.A[i+1]) return false;
    }
    return true;
}   //   isSorted

//insertSort inserts an element in a sorted position
void insertSort(Array *arr, int val)
{
    //if length is < size 
    if (arr->length >= arr->size)
        return;
    if (!isSorted(*arr))
        return;

    int i = arr->length-1; 
    while (arr->A[i] > val)
    {
        arr->A[i+1]= arr->A[i];
        i--;
    }
    arr->A[i+1] = val;
    arr->length++;

    return;
}

void Rearrange(Array *arr)
{
    //rearrange negatives and positives
    int i = 0;
    int j= arr->length-1;
    while (i < j)
    {
        while(arr->A[i] < 0) i++;
        while(arr->A[j] >= 0) j--;
        if (i < j) swap(&arr->A[i], &arr->A[j]);

    }
}

void arrMerge(Array arr1,  Array arr2, Array *arr3)
{
    //all arrays are sorted
    //this allows duplicates to be merged twice
    //this has been tested for two sorted same size arrays.
    //only one of the for loops wll be invoked.
    int i = 0;
    int j = 0;
    int k = 0;
    //struct Array *arr3;
   // arr3->A = (int *) malloc((arr1.size + arr2.size)*sizeof(int));  // i think this might cause a memory leak


    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i]<arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];  // the ++ will invoke after this line
            
        } else{
            arr3->A[k++] = arr2.A[j++];
        }
    }
    for( ;i<arr1.length;i++)
        arr3->A[k++]= arr1.A[i];
    for( ; j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];


}

void arrUnion(Array arr1,  Array arr2, Array *arr3)
{
    //all arrays are sorted
    //UNION of Sorted Arrays
    //this has been tested for two sorted same size arrays.
    //only one of the for loops wll be invoked.
    int i,j,k;
    i = j = k = 0;
    
    //struct Array *arr3;
   // arr3->A = (int *) malloc((arr1.size + arr2.size)*sizeof(int));  // i think this might cause a memory leak

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];  // the ++ will invoke after this line
        
        } else if(arr1.A[i] > arr2.A[j])
        {
            arr3->A[k++] = arr2.A[j++];
        } else
        {
            arr3->A[k++] = arr2.A[i++];
            j++;
        }
    }
    for( ;i<arr1.length;i++)
        arr3->A[k++]= arr1.A[i];
    for( ; j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

    arr3->length = k;
    
}

void arrInterserction(Array arr1,  Array arr2, Array *arr3)
{
    //all arrays are sorted
    //INTERSECTION of Sorted Arrays
    //this has been tested for two sorted same size arrays.
    //only one of the for loops wll be invoked.

    //this is messy the way i left the if statements. I just need an equal and a not equal
    int i,j,k;
    i = j = k = 0;
    
    //struct Array *arr3;
   // arr3->A = (int *) malloc((arr1.size + arr2.size)*sizeof(int));  // i think this might cause a memory leak

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            //arr3->A[k++] = arr1.A[i++];  // the ++ will invoke after this line
            i++;
            //j++;
        } else if(arr1.A[i] > arr2.A[j])
        {
            j++;
            //i++;
            //arr3->A[k++] = arr2.A[j++];
        } else
        {
            arr3->A[k++] = arr2.A[i++];
            j++;
        }
    }
   

    arr3->length = k;
    
}

void arrDifference(Array arr1,  Array arr2, Array *arr3)
{
    //all arrays are sorted
    //Difference arr1 - arr2 of Sorted Arrays
    //if arr1 < arr2 copy arr1.   Dont copy arr2.  Don't copy arr1 if equal
    //this has been tested for two sorted same size arrays.
    //only one of the for loops wll be invoked.
    int i,j,k;
    i = j = k = 0;
    
    //struct Array *arr3;
   // arr3->A = (int *) malloc((arr1.size + arr2.size)*sizeof(int));  // i think this might cause a memory leak

    while (i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];  // the ++ will invoke after this line
        
        } else if(arr1.A[i] > arr2.A[j])
        {
            //arr3->A[k++] = arr2.A[j++];
            j++;
        } else
        {
            //arr3->A[k++] = arr2.A[i++];
            j++; i++;   //they are equal so increment both
        }
    }
    //only copy remaining elements from arr1.  Not from arr2
    
    for( ;i<arr1.length;i++)
        arr3->A[k++]= arr1.A[i];
    

    arr3->length = k;
    
}


// also included using search but he did not code it.  would have to go back and watch white board review.


int main()
{
    Array arr;
    arr.size = 10;
    //initialize the memory for the  array in the structs
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.A[0] = 2;
    arr.A[1] = 4;
    arr.A[2] = 6;
    arr.A[3] = -8;
    arr.length = 4;

    Array arr1;   //cannot initiate like Abdul
    Array arr2;
    Array arr3;
    arr1.A = (int *)malloc(10 * sizeof(int));
    arr1.A[0] = 1;
    arr1.A[1] = 4;
    arr1.A[2] = 5;
    arr1.A[3] = 7;
    arr1.A[4] = 9;
    arr1.size = 10;
    arr1.length = 5;

    arr2.A = (int *) malloc(10 * sizeof(int));
    arr3.A = (int *) malloc(20 * sizeof(int));

    arr2.A[0] = 2;
    arr2.A[1] = 4;
    arr2.A[2] = 6;
    arr2.A[3] = 8;
    arr2.A[4] = 10;
    arr2.size = 10;
    arr2.length = 5;

    arr3.length = 10;
    arr3.size = 20;

    arrDifference(arr1, arr2, &arr3);
    
    arrDisplay(arr3);
    printf("\n\n");
    
    arrDisplay(arr1);

    
    printf("iterating Binary Search for 2: %d \n",arrBinarySearch_it(arr,2));
    printf("recursive Binary Search for 2: %d \n", arrBinarySearch_rec(arr,0,arr.length-1,2));


    arrDisplay(arr);
    arrAppend(&arr, 11);
    arrDisplay(arr);
    arrInsert(&arr,0,99);
    arrDisplay(arr);
    arrDelete(&arr,0);
    arrDisplay(arr);
    
    /*
    if (!(arrSearch(&arr,10) == -1))
        printf("found\n");
    else
        printf("Not found\n");

    printf("Max of array: %d\n",max(arr))    ;
    printf("Sum of array: %d\n",arrSum(arr, arr.length-1));
    printf("Average of array: %f\n", average(arr));

    arrReverse(&arr);
    arrDisplay(arr);
    leftRotate(&arr);
    arrDisplay(arr);
    leftShift(&arr);
    arrDisplay(arr);
    rightShift(&arr);
    arrDisplay(arr);
    */

    insertSort(&arr,7);
    arrDisplay(arr);
    Rearrange(&arr);
    arrDisplay(arr);

    free(arr.A);

    return 0;

}
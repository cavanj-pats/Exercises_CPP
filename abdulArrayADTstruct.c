//array ADT
//structure
//abdul ArrayADTstruct.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  //for boolean

//needed to add struct when using Array.

struct Array
{
    int *A;
    int size;
    int length;
};

void arrDisplay(struct Array arr)
{
    for (int i=0; i<arr.length; i++)
    {
        printf("%d, ",arr.A[i]);
    }
    printf("\n");
}

void arrAppend(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

void arrInsert(struct Array *arr, int idx, int x)
{
    //probably should check that arr->length < arr->size;

    if(idx > arr->length) return;

    for(int i = arr->length; i>idx; i--)
        arr->A[i] = arr->A[i-1];
    
    arr->A[idx] = x;
    arr->length++;

    return;
}

void arrDelete(struct Array *arr, int idx)
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
int arrSearch(struct Array *arr, int value)
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
int arrBinarySearch_it(struct Array arr,  int key)
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

int arrBinarySearch_rec(struct Array arr, int l, int h, int key)
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

int get(struct Array arr, int x)
{
    if (x >= 0 && x < arr.length)
        return arr.A[x];

    return -1;
}

void set(struct Array *arr, int x, int val)
{
    if (x>= 0 && x<arr->length)
        arr->A[x]= val;
}

int max(struct Array arr)
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

int min(struct Array arr)
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

int arrSum(struct Array arr, int n)
{
    //NOTE:  n is the index.  What is sent is arr.length - 1.  if arr.length == 0 then
    // the result will be -1.  This is the situation we need to guard against.
    if (n < 0)
        return 0;
    else
        return arrSum(arr, n-1) + arr.A[n];

}//arrSum

float average(struct Array arr)
{
    if (arr.length>0)
    {
        return (float) arrSum(arr, arr.length-1) / (float) arr.length;
    }
    return 0.0;
}// average

void arrReverse(struct Array *arr)
{
    //uses swap function
    int i, j;
    for (i=0, j = arr->length-1; i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
}  //arrReverse

//left shift
void leftShift(struct Array *arr)
{
    for (int i=1;i<arr->length;i++)
        arr->A[i-1]= arr->A[i];
    
    arr->A[arr->length-1] = 0;
} //left shift

//left rotate
void leftRotate(struct Array *arr)
{
    int temp = arr->A[0];
    for (int i=1;i<arr->length;i++)
        arr->A[i-1]= arr->A[i];
    
    arr->A[arr->length-1] = temp;
} //left rotate

//right shift
void rightShift(struct Array *arr)
{
    for(int i=arr->length-2; i>=0; i--)
    {
        arr->A[i+1]= arr->A[i];
    }
    arr->A[0]=0;
}
//right rotate
void rightRotate(struct Array *arr)
{
    int temp = arr->A[arr->length-1];
     for(int i=arr->length-2; i>=0; i--)
    {
        arr->A[i+1]= arr->A[i];
    }
    arr->A[0]=temp;

}  //rightRotate

bool isSorted(struct Array arr)
{
    for (int i = 0; i<arr.length-1; i++)
    {
        if (arr.A[i] >= arr.A[i+1]) return false;
    }
    return true;
}   //   isSorted

//insertSort inserts an element in a sorted position
void insertSort(struct Array *arr, int val)
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

void Rearrange(struct Array *arr)
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

void arrMerge(struct Array arr1,  struct Array arr2, struct Array *arr3)
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

void arrUnion(struct Array arr1,  struct Array arr2, struct Array *arr3)
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

void arrInterserction(struct Array arr1,  struct Array arr2, struct Array *arr3)
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

void arrDifference(struct Array arr1, struct  Array arr2,struct Array *arr3)
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

//find missing elements.  First in sorted arrays (two methods) then in unsorted arrays.
//arrays of integers.  Once min element is found, print any missing elements until max element
//example   1,2,4     3 is missing
void findMissingSorted1(struct Array arr)
{
    //find missing based on Array element value differences.
    int currval = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        //the first element and the last element are not missing :)
        //this will catch two consecutive missing elements
        if(arr.A[i]-currval == 1)
        {
            currval = arr.A[i]; //move currval to the found elements
        } else
        {
            while(arr.A[i]- currval>1)
                printf("%d, ", ++currval);   
        
            currval = arr.A[i];
        }
        

    }
    printf("\n");
}

void findMissingSorted2(struct Array arr)
{
    //use the difference between the first element value and index
    // 1, 5, 5, 7, 9   elements
    // 0, 1, 2, 3, 4   index
    //this code will not work for duplicate elements adjacent to each other
    //which they must be because this is a sorted array

    int diff = arr.A[0];
    for(int i = 1; i<arr.length; i++)
    {
        if(arr.A[i] == arr.A[i-1]) 
        {
            diff--;  //there is a duplicate so we need to adjust diff down
        }
        else
        {
            while(diff < arr.A[i]-i)
            {
                printf("%d, ",diff+i);
                diff++;  //there is a missing element, for each one we need to adjust diff
            }
        }

    }
    printf("\n");


}
void findMissingUnsorted(struct Array arr)
{
    int minval = min(arr);  //use function I already made
    int maxval = max(arr);   //use previously made function
    //since the above functions each traverse the array, we could build a local function
    //to traverse the loop once and determine both min and maxval

    int *p = (int *) malloc(maxval+1);
    for(int i=0; i<maxval+1;i++){
        p[i]=0;
    }
    for(int j = 0; j<arr.length; j++)
    {
        p[arr.A[j]]++;  //this is a counter for how many times an element is present.
        //same code can be used to find duplicates or more than one occurance of an element
    }
    for(int k=minval;k<maxval+1;k++)
    {
        if(p[k] ==0)
            printf("%d, ",k);
    }
    printf("\n");

}

void findDuplicatesSorted1(struct Array arr)
{
    //array is sorted
    //items can be duplicated more than two times
    int item=arr.A[0];
    int priordup = 0;
    for(int i = 1; i<arr.length; i++)
    {
        if(item ==  arr.A[i] && item != priordup)
        {
            printf("%d, ",arr.A[i]);
            priordup = arr.A[i];
        }
        item = arr.A[i];
    }
    printf("\n");
}

void findCountDuplicatesSorted(struct Array arr)
{
    int j=0;
    for(int i=0; i<arr.length-1; i++)
    {
        if(arr.A[i] ==  arr.A[i+1]){
            j = i+1;
            while(arr.A[i]==arr.A[j]) 
                j++;

            printf("%d found %d time(s).\n",arr.A[i], j-i);
            i=j-1;  //ok to index i as we don't need to traverse elements that we know were duplicates
        }
        
    }
}

//Abdul also had a nested loop techinique for finding duplicates
//he flagged teh duplicate in teh array with a -1.  
//probably teh best way to do that wouidl be to make a copy of the array so that 
//you aren't messing up the orginal values.

void findDuplicatesUnsorted1(struct Array arr)
{
    int *p = (int *)malloc(arr.length*sizeof(int));
    int count=0;

    for(int i = 0; i<arr.length; i++)
        p[i] = 0;  //initialize

    for(int i=0; i<arr.length-1; i++)
    {
        count = 1;

        for(int j=i+1; j<arr.length; j++){
            
            if(arr.A[i] == arr.A[j] && p[j] !=-1)
            {
                count++;
                p[j]=-1;
            }


        }
        if (count > 1)
            printf("%d occured %d times.\n", arr.A[i], count);
    }

    free(p) ;

}

void findDuplicatesUnsorted(struct Array arr)
{
    int minval = min(arr);
    int maxval = max(arr);

    int *p = (int *) malloc(maxval+1);
    for(int i=0; i<maxval+1;i++){
        p[i]=0;
    }
    for(int j = 0; j<arr.length; j++)
    {
        p[arr.A[j]]++;  //this is a counter for how many times an element is present.
        //same code can be used to find duplicates or more than one occurance of an element
    }
    for(int k=minval;k<maxval+1;k++)
    {
        if(p[k]>1)  //p[k] will actually count occurances of an element
            printf("%d, ",k);
    }
    printf("\n");

}


void findSumPairEqualsK(struct Array arr, int k)
{
    //make a hash table
    int maxVal = max(arr);
    int *h = (int *) malloc((maxVal+1) * sizeof(int));
    for(int i = 0; i<maxVal+1; i++)
    {
        h[i]= 0;
    }
    for (int j= 0 ; j<arr.length; j++)
    {
        h[arr.A[j]]++;
    }
    for (int i = 0; i<maxVal+1; i++)
    {
        if(h[i] !=0 && h[k-i] !=0)   
        {
            //we have a match,  print it
            printf("%d and %d total %d.\n", i, k-i, k);

            //this will find 1,9 and 9,1 for example.  So duplicate results.
        }
    }


    free(h);

}

void findSumPairEqualK2(struct Array arr, int k)
{
    //i beleive this is only goign to work for a sorted array
    int i =0;
    int j = arr.length-1;

    while (i<j)
    {
        if (arr.A[i]+arr.A[j]==k)
        {
            printf("%d, and %d = %d\n", arr.A[i], arr.A[j], k);
            i++;
            j--;
        }
        if (arr.A[i]+arr.A[j]>k) j--;
        if (arr.A[i]+arr.A[j]<k) i++;

    }
}


void minMax(struct Array arr)
{
    
    int min = arr.A[0];
    int max = min;
    
    for(int i=0; i<arr.length; i++)
    {
        if (arr.A[i]<min) 
        {
            min = arr.A[i];
            break;
        }
        if (arr.A[i]>max)
            max = arr.A[i];

    }
    printf("Min:= %d\n", min);
    printf("Max:= %d\n", max);


}




int main()
{
    struct Array arr;
    arr.size = 10;
    //initialize the memory for the  array in the structs
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.A[0] = 4;
    arr.A[1] = 1;
    arr.A[2] = 6;
    arr.A[3] = 5;
    arr.length = 4;

    struct Array arr1;   //cannot initiate like Abdul
    struct Array arr2;
    struct Array arr3;
    arr1.A = (int *)malloc(10 * sizeof(int));
    arr1.A[0] = 1;
    arr1.A[1] = 5;
    arr1.A[2] = 5;
    arr1.A[3] = 7;
    arr1.A[4] = 9;
    arr1.size = 10;
    arr1.length = 5;

    printf("arr1:\n");
    arrDisplay(arr1);
    printf("FindMissing in arr1:\n");
    findMissingSorted1(arr1);
    //printf(" Find Missing Sorted Algorithm 1\n");
    findMissingSorted2(arr1);
    findMissingUnsorted(arr1);
    printf("\n Display arr:\n");
    arrDisplay(arr);
    printf("\nFind Missing Unsorted:");
    findMissingUnsorted(arr);
    printf("\nDuplicates in arr1:\n");
    findDuplicatesSorted1(arr1);
    findCountDuplicatesSorted(arr1);
    findDuplicatesUnsorted1(arr1);
    printf("\n");
    findSumPairEqualsK(arr1, 10);
    findSumPairEqualK2(arr1, 10);
    printf("\n");
    minMax(arr1);
    printf("\n");

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
    printf("Array 1:\n");
    arrDisplay(arr1);
    printf("Array 2:\n");
    arrDisplay(arr2);
    printf("Difference Function Resulting arr3:\n");
    arrDisplay(arr3);
    printf("\n\n");
    
    printf("Array:\n");
    arrDisplay(arr);

    
    printf("iterating Binary Search for 2: %d \n",arrBinarySearch_it(arr,2));
    printf("recursive Binary Search for 2: %d \n", arrBinarySearch_rec(arr,0,arr.length-1,2));

    
    printf("Array arr:\n");
    arrDisplay(arr);
    arrAppend(&arr, 11);
    printf("arr with 11 appended:\n");
    arrDisplay(arr);
    arrInsert(&arr,0,99);
    printf("arr with 90 inserted in position 0:\n");
    arrDisplay(arr);

    arrDelete(&arr,0);
    printf("arr with position 0 deleted:\n");
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
    printf("arr with insertSort performed with 7 apparently inserted:\n");
    arrDisplay(arr);
    Rearrange(&arr);
    printf("arr after Rearrange function:\n");
    arrDisplay(arr);

    free(arr.A);
    free(arr1.A);
    free(arr2.A);
    free(arr3.A);

    return 0;

}
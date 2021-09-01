//merge.cpp
//selection sort execise  Week 24 sorting labs
#include <iostream>
#include "cpluspluslabs.h"

using namespace std;

/*
void swap(int *xp, int *yp){
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}
*/

/*
void merge(int arr[], int, int, int);
*/

void merge_sort(int arr[], int left, int right){
    int mid = (left + right)/2;
    if (left == right)
        return;
    else{
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge (arr, left, mid, right);
    }
    
}


/*
void merge(int arr[], int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft + 1;
    int *mergedArr;
    int iRight, iLeft, iRes;
    int size = highRight - lowLeft + 1;
    mergedArr = new int[size];
    iLeft = lowLeft;
    iRight = lowRight;
    iRes = 0;
    while (iLeft <= highLeft && iRight <= highRight){
        if(arr[iLeft]<arr[iRight]){
            mergedArr[iRes]= arr[iLeft];
            iLeft++;
            iRes++;
        }
        else {
            mergedArr[iRes]= arr[iRight];
            iRight++;
            iRes++;
        }
    }
    while (iLeft <= highLeft){
        mergedArr[iRes] =  arr[iLeft];
        iLeft++;
        iRes++;
    }
    while (iRight <= highRight ){
        mergedArr[iRes] = arr[iRight];
        iRight++;
        iRes++;
    }

    for(int i=0, iArr = lowLeft; i<size ; i++, iArr++ ){
        arr[iArr] = mergedArr[i];
    }
    
    delete []mergedArr;


}
*/

/*
void selection_sort(int arr[], int elements){
    int temp;
    int idx;

    for (int i=0;i<elements;i++){
        temp = arr[i];
        idx = i;
        for (int j=i+1; j<elements;j++){
            if(arr[j] < temp){
                temp = arr[j];
                idx = j;
            }
        }
        //swap item at [i] with temp
        if (idx !=i)
            swap(arr[i], arr[idx]);
    }
}


/// Function to print an array /

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
    
    int lst[] = {19, 2, 20, 1, 10, 18};
    printArray(lst, sizeof(lst)/sizeof(lst[0]));

    //selection_sort(lst, 6);
    merge_sort(lst, 0, 6);

    printArray(lst, sizeof(lst)/sizeof(lst[0]));
       

    return 0;

}
*/
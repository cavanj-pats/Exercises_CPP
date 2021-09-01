//swap.cpp
#include <iostream>

using namespace std;

//using reference 
void refswap(int &x, int &y){
    //int temp=x;  the code looks cleaner when using references
    //but you really don't know you are working with references.
    x=x+y;
    y=x-y;
    x=x-y;
}


void swap(int *xp, int *yp){
    int temp;
    temp = *xp;
    *xp = *yp;
    *yp = temp;
}



///* Function to print an array */

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 



int main(){
    
    int lst[] = {19, 2, 20, 1, 0, 18};
    printArray(lst, sizeof(lst)/sizeof(lst[0]));

    refswap(lst[0],lst[1]);

    
    printArray(lst, sizeof(lst)/sizeof(lst[0]));

    swap(&lst[0], &lst[1]);

     printArray(lst, sizeof(lst)/sizeof(lst[0]));


    return 0;

}

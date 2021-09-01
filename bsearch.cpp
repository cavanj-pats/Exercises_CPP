//bsearch.cpp
//#include <iostream>
#include <stdio.h>
//#include <iomanip>



using namespace std;


int binary_search( int val, int srtArr[], int srtArrSize){
    int low, high, mid;
    int ind;
    int counter=0;
    bool found = false;
    low = 0;
    high = srtArrSize;
    while (( found == false) && (low<=high) ){
        counter++;
        mid = (low + high)/2;
        if (srtArr[mid] == val){
            ind = mid;
            found = true;
           // return ind;   //just stop searching
        }
        else if (val < srtArr[mid])
            high = mid -1;
        else //val > srtArr[mid]
            low = mid + 1;

        
    }
    /*
    if (found == true)
        return ind;
    else
        return counter;
    */
   return counter;

      
}

/*
int main(){
    
    int lst[] = {0, 1, 2, 18, 19, 20, 25};

    printf("%i",binary_search(17, lst, 7));
    
       

    return 0;

}
*/
//firstword.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double* getDoubles(int size){
    double* temp = new double[size];  //temp is pointer to an array
    for(int i=0 ; i<size; i++)
        temp[i]= (double) (i+1)/3.0;
    return temp;      //temp is an address
}

int main(){
    int x = 11;
    double* arr= getDoubles(x);   //arr is a pointer to an array

    for(int i=0 ; i<x; i++)
        cout << arr[i] << endl;

     /*  iterating does not work for this array
    for (int n : arr )
        cout << arr[n] << endl;
    */

    arr = NULL;

    delete[] arr;

    
    

    return 0;

}

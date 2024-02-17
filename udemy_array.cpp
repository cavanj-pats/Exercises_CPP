//udemy array work
//udemy_array.cpp

#include <iostream>
#include <stdio.h>

using namespace std;


int main(){
    int A[4];
    A[0] = 9;
    A[1]= 2;
    A[2] = 1;
    //A[3]= 7;
    //variable sized arrays cannot be initialized. 

    std::cout << sizeof(A) << std::endl;
    std::cout << A[1] << std::endl;
    printf ("%d \n", A[0])  ;




    return 0;
}
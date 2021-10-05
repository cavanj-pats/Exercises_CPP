///CH 09   EX 02
///CH09ex9.cpp
//09/20/2021     webarchive
//ch 09 is about references


#include <iostream>

using namespace std;

int main (){
    int varOne = 6;
    const int * const xPtr = &varOne;
    //int & xRef=x;
    *xPtr = 7;
    int varTwo ;
    xPtr = &varTwo;


    return 0;
    

}
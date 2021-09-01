//Fibonacci Lab
//print out fibonacci numbers based on user input
//fibonacci.cpp
#include <iostream>
//#include <stdlib.h>  //for conversion of command line argument to int

using namespace std;

int main(){
	int n=0;
    int counter=0;
    int fib=1;
    int outFib = 0;
    int inFib = 0;
    cout << "Please enter a positive integer greater than 1: " ;
    cin >> n;
    while (counter <n){
        inFib=fib;
        cout << fib << endl;
        fib += outFib;
        outFib = inFib;

        counter++;        
    }     
	
        
	return 0;
}
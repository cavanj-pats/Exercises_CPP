//Fibonacci Lab
//print out fibonacci numbers based on user input
//fibonacci_rec.cpp
#include <iostream>
//#include <stdlib.h>  //for conversion of command line argument to int

using namespace std;

int fib(int n);

int main(){
	int n=0;
    int counter=0;
    //int fib=1;
    //int outFib = 0;
    //int inFib = 0;
    cout << "Please enter a positive integer greater than 1: " ;
    cin >> n;
    
    cout << "\n Fibonacci Sum: " << fib(n)<< endl;
	
        
	return 0;
}

int fib(int n){
    if(n==1 || n==2) 
        return 1;
    else
        return fib(n-1)+ fib(n-2);

}
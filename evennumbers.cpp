//even numbers lab
//evennumbers.cpp
#include <iostream>
//#include <stdlib.h>  //for conversion of command line argument to int

using namespace std;

int main(){
	int n=0;
    cout << "Please enter a positive integer: " ;
    cin >> n;
    if (n>1){
        for (int i=2;i<=2*n; i+=2){
            cout << i << endl;
        }        
    }
        
	return 0;
}
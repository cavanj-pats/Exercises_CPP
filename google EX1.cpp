//Exercize 1 from Google  Practice
//8/29/2021
//google web site

#include <iostream>
#include <math.h>


using namespace std;

bool isSquare(long int x){
    //if sqrt and <long> sqrt are equal then true
    // y = <long> sqrt(x);
    if (sqrt(x) == static_cast <long int> (sqrt(x)) ) return true;
    return false;
    }


int main(){
    //find a number that is sum of integers and also pefect square
    //36 is such a number
    cout <<"\nGoogle Exercise 1: Find numbers that are sum of integers and perfect square\n";
    cout <<"36 is both a sum of integers and a perfect square.  See below for others after 36.\n\n";
    long int i=0, j=0 , num=0;
    for (i=1; i <=10000; i++){
        j+=i;
        if (i>1 && isSquare(j)){ 
            cout << "Sum of 1-" << i << " is " << j << ". Square root of "<< j << " = " << sqrt(j) <<  endl; 
            //break;
        }
    }


    //cout << isSquare(37) << endl;

    return 0;


}
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
    //36 is such a numer

    long int i=0, j=0 , num=0;
    for (i=1; i <=10000; i++){
        j+=i;
        if (i>1 && isSquare(j)){ 
            cout << "Num is " << i << " " << j << " Sum of integers is a square. " << sqrt(j) << " " << endl; 
            //break;
        }
    }


    //cout << isSquare(37) << endl;

    return 0;


}
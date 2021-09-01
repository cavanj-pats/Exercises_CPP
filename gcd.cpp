//Greatest Common Divisor
//uses recursion to go through GCD function
//the only time a value is returned is when y==0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y){
    if (y==0)
        return x;
    else
       return gcd(y, x%y);
}


int main(){
    cout << "gcd(12,18)= " << gcd(12,18) << endl;

    
       

    return 0;

}

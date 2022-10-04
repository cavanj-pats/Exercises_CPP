//sum of first N natural numbers

#include <stdio.h>

using namespace std;

//could also use n(n+1)/2

//abdul also had an iterative option using a for loop

int sumN(int n){
    if (n>0){
        return n+sumN(n-1);
    
    }else{
        return 0;
    }
}

int main(){
    int x =8;
    printf("Sum N:%d  = %d\n", x, sumN(x));

    return 0;
}
//abdul Factorial N

#include <stdio.h>

using namespace std;

//could also use n(n+1)/2

//abdul also had an iterative option using a for loop

int factorialN(int n){
    if (n>1){
        return n*factorialN(n-1);
    
    }else{
        return 1;
    }
}

int main(){
    int x =5;
    printf("Factorial N:%d  = %d\n", x, factorialN(x));

    return 0;
}
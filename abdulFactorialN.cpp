//abdul Factorial N

#include <stdio.h>

using namespace std;





int factorialN(int n){
    if (n>1){
        return n*factorialN(n-1);
    
    }else{
        return 1;
    }
}

int IfactorialN(int n){
    int f = 1;
    for (int i=1; i<=n; ++i){
        f *= i;
    }
    return f;
}

int main(){
    int x =5;
    printf("Factorial N:%d  = %d\n", x, factorialN(x));
    printf("IFactorial N:%d  = %d\n", x, IfactorialN(x));

    return 0;
}
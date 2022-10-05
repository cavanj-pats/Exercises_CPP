//pow(m,n)

#include <stdio.h>

using namespace std;

int pow(int m, int n){
    if (n == 0 )
        return 1;
    else
        return m * pow(m,n-1);
}

int fastpow(int m, int n){
    if (n==0)
        return 1;
    
    if (n%2 == 0)
        return fastpow(m*m, n/2);
    else  
        return m*fastpow(m*m, n/2);  

}

int main(){
    int m = 2;
    int n = 5;

    printf("%d \n", pow(m,n));
    printf("%d \n", fastpow(m,n));

    return 0;
}
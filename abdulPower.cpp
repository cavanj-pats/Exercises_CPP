//pow(m,n)

#include <stdio.h>

using namespace std;

int pow(int m, int n){
    if (n == 0 )
        return 1;
    else
        return m * pow(m,n-1);
}

int main(){
    int m = 2;
    int n = 4;

    printf("%d \n", pow(m,n));

    return 0;
}
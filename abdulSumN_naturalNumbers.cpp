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

int Isum(int n)
{
    int s=0;
    for (int i=1; i<=n; i++)
        s+=i;

    return s;
}

int Csum(int n)
{
    return (n*(n+1))/2;
}

int main(){
    int x =8;
    printf("Sum N:%d  = %d\n", x, sumN(x));
    printf("Isum N:%d = %d\n",x,Isum(x));
    printf("Csum N:%d = %d\n",x,Csum(x));


    return 0;
}
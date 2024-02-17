//nested recursion

#include <stdio.h>

using namespace std;

int fun(int n){
    if (n>100){
        return n-10;
    }else{
        return fun(fun(n+11)) ;
    }

}



int main(){
    printf ("%d", fun(82));

    return 0;
    
}
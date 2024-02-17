//AbdulRecursionExample

#include <iostream>
#include <stdio.h>

using namespace std;

void fun(int n){
    if (n>0){
        //fun(n - 1);
        printf ("%d ",n);
        fun(n-1);  //put recursive statement here it is TAIL
        fun(n-1);
    }
}

int main(){
    fun(3);
    //cout << endl;
    printf("\n");
    return 0;
}
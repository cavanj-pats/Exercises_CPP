//recStaticGlobal.cpp
//testing of recursion with static and global variables

#include <stdio.h>
#include <iostream>

using namespace std;

int y = 0;

int fun(int n){
    static int x = 0;
    if (n>0){
        x++;
        return fun(n-1) + x;
    }
    return 0;
}

int fung(int n){
    if (n>0){
        y++;
        return fung(n-1)+y;

    }

    return 0;
}

//fun1 is the base function
int fun1(int n){

    if (n>0){
        //head
        return fun1(n-1) + n;
    }

    return 0;

}


int main(){
    int x1 = 5;

    printf("fun1(%d)= %d \n", x1, fun1(x1));
    //std::cout << endl;

    printf ("Static run #1 %d\n", fun(x1));
    printf ("Static run #2 %d\n\n", fun(x1));
    //std::cout << endl;
    printf ("Global run #1 x1: %d = %d\n", x1,fung(x1));
    printf ("Global run #2 x1: %d = %d\n\n", x1,fung(x1));


    return 0;
}
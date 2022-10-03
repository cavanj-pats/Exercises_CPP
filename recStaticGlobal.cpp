//recStaticGlobal.cpp
//testing of recursion with static and global variables

#include <stdio.h>
#include <iostream>

using namespace std;

int fun1(int n){

    if (n>0){
        //head
        return fun1(n-1) + n;
    }

    return 0;

}


int main(){
    int x1 = 5;

    printf("fun1(%d)= %d", x1, fun1(x1));
    cout << endl;

    return 0;
}
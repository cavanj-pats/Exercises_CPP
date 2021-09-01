//stacktester.cpp

#include <iostream>

#include "stack.h"

using namespace std;

int main(){
    int i=1;
    Stack mystack;
    //cout << mystack.top << endl;
    //mystack.push(10);
    //cout<<mystack.peek() << endl;
    //cout << mystack.top << endl;

    //mystack.push(150);
    //mystack.push(200);
    while (i<=1001){
        if (!mystack.push(i)){
            cout << "Push is False at i: "<<i<< endl ;
        }
        i++;
    }
    
//cout << mystack.pop()<< endl;
    
 

    
    return 0;

}
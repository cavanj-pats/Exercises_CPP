//references.cpp   working with references

#include <iostream>

using namespace std;

void setSeven(int *s){
    *s=7;
}

void setTellMe (int *s, int num){
    *s = num;
}

int main(){
    int x = 0;
    int &ref =x;  //makes a referernce to x   a reference is an alias.fs
    cout << "x = " << x << endl;
    cout << "&x = "<< &x << endl;
    setSeven(&x);
    cout << "set x to 7= "<< x << endl;

    x=9;
     cout << "after x= 9= " << x << endl;
     cout << "&x = "<< &x << endl;
    
    setTellMe(&x, 65);
     cout << "after x= TellMe= " << x << endl;
     cout << "&x = "<< &x << endl;
    ref = 23;
    cout << "after x= &ref= " << x << endl;
     cout << "&x = "<< &x << endl;

    return 0;
    
}
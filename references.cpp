//references.cpp   working with references

#include <iostream>

using namespace std;

void setSeven(int *s){
    *s=7;

}

int main(){
    int x = 0;
    cout << "x = " << x << endl;
    cout << "&x = "<< &x << endl;
    setSeven(&x);
    cout << "set x to 7= "<< x << endl;
    
    return 0;
    
}
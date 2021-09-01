//firstword.cpp
#include <iostream>
#include <string>

using namespace std;

void addOne (int *ptrNum){
    *ptrNum=*ptrNum + 1;
}

int main(){
    int x = 11;
    int *intPtr = &x;


    cout << "Address of x " << intPtr << endl;
    cout << "Dereference ptr "<< *intPtr << endl;
    cout << "address of ptr " << &intPtr << endl;
    addOne(&x);
    cout << "After addOne " << *intPtr << endl;
    cout << "Address of x " << intPtr << endl;
    cout << "Dereference ptr "<< *intPtr << endl;
    cout << "address of ptr " << &intPtr << endl;
    

    return 0;

}

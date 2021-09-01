//firstword.cpp
#include <iostream>
#include <string>

using namespace std;



main(){
    int x = 11;
    int *intPtr = &x;


    cout << "Address of x " << intPtr << endl;
    cout << "Dereference ptr "<< *intPtr << endl;
    cout << "address of ptr " << &intPtr << endl;
    

    

    return 0;

}

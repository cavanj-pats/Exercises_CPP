//http://web.archive.org/web/20130318122320/http://newdata.box.sk/bx/c/htm/ch08.htm#Heading3
//playing with pointers so that I understand them better


#include <iostream>

using namespace std;

int main(){
    int theVariable = 5;
    int * pPointer = &theVariable ;

    cout <<"theVariable "<< theVariable << endl;
    cout << "&theVariable " << &theVariable << endl;
    cout << endl;
    cout << "*pPointer " << *pPointer << endl;
    cout << "pPointer " << pPointer << endl;
    cout << "&pPointer " << &pPointer << endl;
    cout << endl;

    *pPointer = 9;
    cout <<"theVariable "<< theVariable << endl;
    cout << "&theVariable " << &theVariable << endl;
    cout << endl;
    cout << "*pPointer " << *pPointer << endl;
    cout << "pPointer " << pPointer << endl;
    cout << "&pPointer " << &pPointer << endl;
    

    cout << "\n\n\n";


//LISTING 8.3   gotta remember int * pAge = &myAge assigns address of myAge to pAge.
///

     unsigned short int myAge = 5, yourAge = 10;
     unsigned short int * pAge = &myAge;  // a pointer
    
    cout << "myAge:\t" << myAge <<  "\tyourAge:\t" << yourAge << "\n";
    cout << "&myAge:\t" << &myAge <<  "\t&yourAge:\t" << &yourAge <<"\n";
    cout << "pAge:\t" << pAge << "\n";
    cout << "*pAge:\t" << *pAge << "\n";
    
    pAge = &yourAge;       // reassign the pointer

       cout << "myAge:\t" << myAge <<  "\tyourAge:\t" << yourAge << "\n";
       cout << "&myAge:\t" << &myAge <<  "\t&yourAge:\t" << &yourAge <<"\n";

       cout << "pAge:\t" << pAge << "\n";
      cout << "*pAge:\t" << *pAge << "\n";

      cout << "&pAge:\t" << &pAge << "\n";

    return 0;
}
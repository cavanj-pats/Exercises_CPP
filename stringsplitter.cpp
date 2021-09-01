//stringtest.cpp
#include <iostream>
#include <string>
//#include "std_lib_facilities.h"


using namespace std;

bool isStrLenOdd(string s){
    if (s.length()%2 == 0)
        return false;
    else
        return true;
    
}


int main(){
string str;
string str1, str2;
char ch;


cout << "\nEnter an odd length string: ";
getline (cin, str);

if ( ! isStrLenOdd(str)) {
    cout << str << " Is not odd\n";
    return -1;
}
else {
    cout << "Middle character: " << str[str.length()/2] << endl;

    cout << "First half: ";
    for(int i=0; i<=str.length()/2-1; i++){
        //first half of string
        cout << str[i];
    }
    cout << endl << "Second half: ";
    
    for (int i=str.length()/2+1; i<str.length();i++){
        cout << str[i];
    }
    
}



return 0;
}


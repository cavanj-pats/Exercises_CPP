//stringtest.cpp
#include <iostream>
#include <string>

using namespace std;


int main(){
string str = "abc";
string str1, str2;
char ch;


cout << str << "def\n";
cout << str+"def\n" ;
cout << "\nPlease enter your name: ";
getline (cin, str);
cout <<"Hello "<< str <<endl;
str1="abcdefg";
ch = str1[3];
cout << str1 << " "<< ch << " " << str1.substr(3,2) << "\n";
cout << "Your Name backwards\n";
for (int i=str.length()-1; i>=0; i--){
    cout << str[i];
}

cout<< endl;

cout << "Enter three words separated by a space: ";
cin >> str >> str1>> str2;
cout << endl;

if (str < str1 && str1 < str2)
    cout << str << " "<< str1 << " "<< str2 << endl; 
else if (str < str1 && str2 > str1)
    cout
else if( str1 < str && str < str2) 
    cout << str1 << " "<< str << " "<< str2 << endl;
else if( str2 < str1 && str1 < str)
    cout << str2 << " "<< str1 << " "<< str << endl;
else if (str1 < str2 && str2 < str)
        cout << str1 << " "<< str2 << " " << str << endl;

return 0;
}


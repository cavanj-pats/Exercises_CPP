//firstword.cpp
#include <iostream>
#include <string>

using namespace std;

string firstword(string s){
    //int i;
    
    if(s.find(' ') != string::npos )
        return s.substr(0, s.find(' '));
    else
        return "e";

}
/*
int main(){
//string str;

cout << firstword("The quick brown fox.")<< endl;




return 0;
}
*/

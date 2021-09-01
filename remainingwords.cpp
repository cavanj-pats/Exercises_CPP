//firstword.cpp
#include <iostream>
#include <string>

using namespace std;

string remainingwords(string s){
    //int i;
    
    if(s.find(' ') != string::npos )
        return s.substr(s.find(' ')+1);
    else
        return "e";

}
/*
main(){
//string str;

cout << remainingwords("The quick brown fox.")<< endl;

return 0;
}
*/

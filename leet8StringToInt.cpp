//string to integer  MyAtoi 

/*
sort of like the calculator grammar
string
leading whitespace ignored
if first non whitespace is a "+" or "-" then read it in.  if none, take it to be +
read all characters that are numbers to read as a number
stop at end  or 

whitespace  sign  number   text
*/


#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int number(string, int);
int sign (string, int);

int whitespace(string s, int start){
    for( int i=start; i<s.length()-1; i++)
        if(s[i]!=' ')
            return sign(s, i);


    return 0;  //empty string was rec'd
}

int sign(string s, int start){
    if(s[start]=='-') return -1* number(s, start+1);
    if(s[start]=='+') return number(s, start+1);
    return number(s,start);
}

int number(string s, int start){
    //if not a number return 0
    //if leading zero ignore
    int end;
    int x=0;
    int temp=0;
    bool val = false;
    bool stop = false;
    string num="";
    for(int i=start; i<s.length(); i++){
        if(s[i]-48 >0 && !val) val=true;
        if(s[i]-48 >= 0 && s[i]-48 <=9){
            if(val && !stop) num = num + s[i]; //if i don't use {} it wont go to else
        }
        else{
            if(!stop) end = i-1; 
            stop = true;
             
        }

    }

    for(int j=end; j>=start; j--){
        temp+=(s[j]-48)*pow(10,x);
        x++;
    }
    
    return temp;

}

class Solution {
public:
    int myAtoi(string s) {
        return whitespace(s, 0);
    }
};


int main(){
    Solution sol;

    //int x = sol.myAtoi("   0002147483649");
    int x = sol.myAtoi("     +987654 Peckerhead");
    cout << x << endl;

    return 0;
}
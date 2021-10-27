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

long long int number(string, int);
int sign (string, int);

int whitespace(string s, int start){
    for( int i=start; i<s.length(); i++){
        if(s[i]==' '){
            //do nothing
        }
        else{
            switch(s[i]-48){
                case 0:case 1: case 2: case 3: case 4: case 5: case 6:
                case 7: case 8: case 9:
                    return sign(s, i);
                    break;

                default:
                    if(s[i]=='-' || s[i]=='+') return sign(s,i);
                    return 0;
            }
        }
    }
            


    return 0;  //empty string was rec'd
}

int sign(string s, int start){
    long long int temp=0;
    if(s[start]=='-')temp = -1* number(s, start+1);
    
    if(s[start]=='+') {
        temp =  number(s, start+1);
    }
    else{
      if(temp==0) temp = number(s,start);  
    }
    
    if(temp <= 1*pow(-2,31)) return 1*pow(-2,31);
    if(temp>=pow(2,31)-1){
        return 1*pow(2,31)-1;
    }
    else{
        return temp;
    }
    
}

long long int number(string s, int start){
    //if not a number return 0
    //if leading zero ignore
    int end;
    int x=0;
    long long int temp=0;
    bool val = false;
    bool stop = false;
    string num="";
    /*
    switch(s[start]-48){
        case 0:case 1: case 2: case 3: case 4: case 5: case 6:
        case 7: case 8: case 9:
            break;

        default:
            return 0;
    }
    */
    for(int i=start; i<s.length(); i++){
        if(s[i]-48 >0 && !val) val=true;

        if( (s[i]-48 >= 0 && s[i]-48 <=9)){
            if(val && !stop) num = num + s[i]; //if i don't use {} it wont go to else
            if(i==s.length()-1 && !stop){
                //this is invoked if reached end of string
                end = i;
                stop = true;
            }

        }
        else{
            //this is invoked if the string has non-numeric characters after numbers
            if(!stop) end = i-1; 
            stop = true;
             
        }

    }
    if(num.length()>10) return pow(2,31);

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

   // int x = sol.myAtoi("   0002147483648");
    int x = sol.myAtoi("  w -2147483646");
    cout << x << endl;

    return 0;
}
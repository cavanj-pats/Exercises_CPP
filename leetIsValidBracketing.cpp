//proper bracketing

#include <string>
#include <iostream>

using namespace std;

/*  grammar
an open is to be followed by a close or an open of a different type
the last opened must be the first closed
the first opened must be the last closed
those opened must be closed in reverse order.

open is a type ()[]{}
    open of another type
    close of same type
*/

bool isValidHelper(string s, int pos);
bool isOpen(char c);


class Solution {
public:
    bool isValid(string s) {
        int pos=0;
        

        return isValidHelper(s, pos);
            
        }
        
        
    };
    
    bool isOpen(char c){
        if(c=='(' || c=='{' || c == '[') return true;
        return false;
    }
    
    bool isClosed(char c){
        if(c==')' || c=='}' || c == ']') return true;
        return false;
    }


bool isValidHelper(string s, int pos){
   bool correctClose = false;
       
    int trueCount=0;
    int falseCount=0;
        
    if(s.length()%2 !=0) return false;  // odd number of elements is not valid   

    for(int i=0; i<s.length();i++)
        if(isOpen(s[i]))
            trueCount++;
        else    
            falseCount++;

    if(trueCount != falseCount) return false;  //there is a mismatch of opens and closes

   
    while(s.size()>0 && pos < s.size() ){     
        if(isOpen(s[pos]) && !isOpen(s[pos+1])) 
            if((s[pos]=='(' && s[pos+1] ==')' )||
               (s[pos]=='[' && s[pos+1] ==']' )||
               (s[pos]=='{' && s[pos+1] =='}' )){
                s.erase(pos,2);
                correctClose = true;
                pos=0;
            }
            else
               return false;  //there is an open and a close but they are different types.

        else
            pos++;
    }
    return correctClose;  //if it gets here all opens are correctly closed.
        
}


int main(){
    Solution sol;

    cout << sol.isValid("([)]") <<endl;

    return 0;
}
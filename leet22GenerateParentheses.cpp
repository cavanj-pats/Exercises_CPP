//leet   22.Generate Parentheses

#include <iostream>
#include <string>
#include <vector>


using namespace std;

void genParenHelper(int, int,  string , vector<string> &ans);
bool isValidHelper(string s, int pos);
bool isOpen(char c);

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        genParenHelper(n,0, str,  ans);
        return ans;
    }
};

void genParenHelper(int n, int pos, string str,  vector<string> &ans){
    
    //string str3, str4;
    //str3="";
    //str4 = "";

    //generate ((())) , (()()),(())(), ()(()), ()()()
    //there are n*2-1 permutations

    //  n-n, n-1 - n-1 1-1,  n-2 - n-2 2-2, ...
    //if n==1 ()
    //if n==2   (()), ()()
    //if n==3  ((())), (())(), (()()), ()(()),()()()

    //if n is odd, then there will be n*2-1 pairs
    //if ne is even,  there will be n*2 pairs
   
    //if(n%2 !=0) oddPairs=true;
    
    if(pos == n*2){
        if(isValidHelper(  str,0)) 
            ans.push_back( str);
    }
    else{
        if(str.length()==pos)
            str.push_back( '(');//can't assign a position in string that does not exist
        else 
            str[pos]='(';
        //str[pos] = '(';
        genParenHelper(n,pos+1,str,ans);
        
            str[pos] = ')';
        genParenHelper(n,pos+1, str, ans);

    }


  
    //the number of permutations is n-1
    /*
    if(n % 2 == 0) 
        loop = n*2;
    else
        loop = n*2-1;
*/
   // if(n%2 !=0) oddPairs=true;



   /*

    if(n==1) ans.push_back("()");
    if(n=2){
        ans.push_back("(())");
        ans.push_back("()()");
    }
    if(n>2){

        while(pos<n){
            str="";
            str2="";
            
            
            for(int i=0; i<n-pos; i++){
                str = str + "(";
                str2=str2+")";
            }
            str = str+str2;
            str2="";
            for(int i=n-pos; i<n;i++){
                str=str +"(";
                str2 = str2 + ")";

            }          
            str = str + str2;
            ans.push_back(str);  //((())),(())(),()(()) for n=3  just missing ()()() and (()())
        
        pos++;
        }
            str3="";
            str4="(";
            for(int i=0; i<n;i++){
                str3=str3 + "()";
                if(i>0) str4 = str4+"()";
            }
            ans.push_back(str3);
            ans.push_back(str4+")");

            */
           
    
      
}

bool isOpen(char c){
        if(c=='(' || c=='{' || c == '[') return true;
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
    vector<string> ans;
    int num=4;
    Solution sol;
    ans = sol.generateParenthesis(num);
    cout << "num= "<< num << endl;
    cout << "Solution Size= "<< ans.size() << endl;
    cout << "PAIRS:\n";
    for(int i = 0; i<ans.size(); i++)
        cout << ans[i] << ", ";

    cout << endl;
        return 0;

}
        
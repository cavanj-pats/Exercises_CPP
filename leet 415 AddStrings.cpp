//leet 415 add two strings
//accepted  lowest 30% performance

#include <iostream>
#include <string>
#include <cmath> 
#include <vector>
#include <stack>
#include <map>


using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        map <char, int> digit = {{'0',0}, {'1',1}, {'2',2}, {'3',3}, {'4',4}, {'5', 5}, {'6', 6}
                        ,{'7',7}, {'8',8},{'9', 9}};
        
        map<int, char> charResult = {{0,'0'},{1,'1'}, {2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},
                                    {8,'8'},{9,'9'}};

        int carry = 0;
        stack<char> temp;
        

        int j = num2.size()-1;
        int i = num1.size()-1;
        int d1=0, d2=0, dResult=0;
        string result = "";
        d1 = digit[num1[i] ];
        d2 = digit[num2[j] ];

        while (i>=0 || j >= 0 || carry != 0){
             
             dResult = d1 + d2 + carry;
             if (dResult >= 10){
                 carry = 1;
                 dResult-=10;
             } else{
                 carry = 0;
             }

            temp.push(charResult[ dResult]);
            --i;
            --j;
            if (i < 0){
                d1=0;
            }
            else{
                d1=digit[num1[i] ];
            }
            if (j<0){
                d2 = 0;
            }
            else{
                d2=digit[num2[j] ];
            }
            

        }

                        
        for (int i = temp.size()-1; i>=0; --i){
            
            result += temp.top();    
            temp.pop();

            
        }
        
        return result;
        
       
    }

};


int main(){
    Solution sol;
    string ans = sol.addStrings("1", "9");

    cout << "56 + 4 =: " << ans << endl;

    return 0;
}
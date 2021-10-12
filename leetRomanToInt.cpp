//Roman to Integer

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        //need to find 1-Special cases, 2- their position 
        int val=0;
        int i=0;
        string t;
        bool special = false;

        while (i<s.size())
        {
            special = false;
            t=s.substr(i,2);

            if (t=="IV"){
                val += 4;
                i+=2;
                special = true;
            }

            if(t== "IX"){
                val += 9;
                i+=2;
                special = true;
            }
            if(t=="XL"){
                    val += 40;
                    i+=2;
                    special = true;
            }
            if(t=="XC"){
                    val += 90;
                    i+=2;
                    special = true;
            }
            if(t=="CD"){
                    val += 400;
                    i+=2;
                    special = true;

            }
            if(t=="CM"){
                val+=900;
                i+=2;
                special = true;
            }

            if (!special){
                t=s.substr(i,1);
                if(t== "I"){
                        val +=1;
                        i++;
                }
                if(t=="V"){
                        val +=5;
                        i++;
                }
                if(t=="X"){
                        val+=10;
                        i++;
                }
                if(t=="L"){
                        val += 50;
                        i++;
                }
                if(t=="C"){
                        val += 100;
                        i++;
                }
                if(t=="D"){
                        val += 500;
                        i++;
                }
                if(t=="M"){
                        val += 1000;
                        i++;
                }
                        
            }
        }
    
        return val;
        
    } //end romanToInt
};



int main(){
    Solution sol;

   // cout << "Roman LVIII to int: " << sol.romanToInt("LVIII") << endl;
    //cout << "Roman MCMXCIV to int: " << sol.romanToInt("MCMXCIV") << endl;
    cout << "Roman MCDLXXVI to int: " << sol.romanToInt("MCDLXXVI") << endl;
    //cout << "Roman IX to int: " << sol.romanToInt("IX") << endl;


    return 0;

}
//leet 1177 make palindrome from substring
//12/12/2021   date is close to being a palindrome

#include <iostream>
#include <vector>

using namespace std;

bool palPal(string);

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> ans;
        for(auto q: queries){
            string temp = s.substr(q[0], q[1]-q[0]+1);
            bool isPali = palPal(temp);
            int pos = q[2];
            int strLength = temp.size();

            
            int i = 0;
            while (pos > 0 && !isPali){
            //for(int i=0; i<strLength;++i){
                if(temp[i] != temp[strLength-1-i]){
                    temp[strLength-1-i] =  temp[i];
                    pos--;  //made one move
                    isPali = palPal(temp);
                            
                        
                        
                }
                ++i;
                if (i > strLength/2) break;


            }

            ans.push_back(isPali);
            

        }
        
        return ans;
    }
};

bool palPal(string str){
    int length =0;
    switch (str.length()){
        case 1:
            return true;
            break;  //just to have it
        case 2: case 3:
            if(str[0] == str[str.length()-1])
                return true;
            else 
                return false;    
                break;            
        default:
            if((str[0] != str[str.length()-1]) || (str[1] != str[str.length()-2])){
                return false;  //whenever this happens return false
            }
            else{
                length = str.length()-2;
               // if (isPalindrome( atoi( str.substr(1,length).c_str() ) ) )
               if(palPal(str.substr(1,length)))
                    return true;
                else 
                    return false;
                       
            }
            break;
    }
}


int main(){
    Solution sol;
    string s = "hunu";
    vector <vector <int>> queries = {{0,3,1},{1,2,0},{0,3,1},{0,3,2}};
    vector <bool> ans = sol.canMakePaliQueries(s, queries);

    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << ", ";
    }
    

    return 0;

}
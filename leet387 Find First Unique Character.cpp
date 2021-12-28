//leet 387 first non repeating character

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
       // char t;
        int strSize = s.length();
        int i=0;
        int found;

        if (strSize == 0 ) return -1;

        while (i<strSize){
            if (s[i] != '*'){
                found = s.substr(i+1, strSize-(i+1)).find_first_of(s[i], 0);
                if (found == -1){
                    return i;
                    break;
                } else
                {
                    //need to replace all occurrances of s[i] with a dummy character, say "*"
                    int j=i+1, k= strSize-1;
                    while (j <= k){
                        if (s[j] == s[i] ){
                            s[j] = '*';
                            
                        }
                        if (s[k] == s[i]){
                            s[k] = '*';
                            
                        }
                        ++j;
                        --k;
                    }
                    s[i] = '*';
                }
            }

            ++i;
        }

        return -1;

    }
};


int main(){
    Solution sol;
    
    string s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl;
    return 0;
}
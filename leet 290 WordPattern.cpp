//leet 290 word pattern
//                     1/18/2022  leetcode
/*                        submitted and accepted

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between 
a letter in pattern and a non-empty word in s.
 
Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream iss(s);
        vector<string> inputString;
        unordered_map <char, int> patternMap;
        unordered_map <string, char> sMap;
        unordered_map <char, string> resultMap;
        string temp;


        int i=0;
        //int j=0;
        while (iss >> temp){
            inputString.push_back(temp);
            resultMap.emplace(pattern[i], temp);
            sMap.emplace(temp, pattern[i]);
            ++i;
            
            /* patternMap.emplace(pattern[i],++i);
            sMap.emplace(temp,++j);
            resultMap.emplace(pattern[i], temp); */
           
        }

        if (pattern.size() != inputString.size()) return false;
        if (resultMap.size() != sMap.size()) return false;

        for(int m=0; m<pattern.size(); ++m){
            if (inputString[m] != resultMap[ pattern[m] ]) return false;
            if (pattern[m] != sMap[inputString[m]]) return false;
            
        }

      

        return true;
    }
};

int main(){
    string pattern = "aaa";
    string s = "aa aa aa aa";
    Solution sol;
    
    cout << sol.wordPattern(pattern, s) << endl;

    return 0;
}
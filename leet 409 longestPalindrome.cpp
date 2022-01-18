//409 longest pali

//longest palindrondrome possible from a string.
//I just keep track of teh length. I don't bother matching any characters.
/*
make a map of teh characters and keep track of how many of each character
if the character count is even we can use all of them in a palindrome.  Keep track of teh length
If the character count is odd,  i use all but the last one.  add all but one to length
Store teh extra one in a map
if at the end there is at least one single character add one to length because we can put that in the middle
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> charCount;
        map<char, int> singleChar;
        int length=0;

        for (int i = 0; i<s.size(); ++i){
            charCount[s[i]]++;
        }

        // show content:
        for (std::map<char,int>::iterator it=charCount.begin(); it!=charCount.end(); ++it)
            if(it->second % 2 == 0){
                length += it->second;
            } else{
                singleChar[ it->first]++;
                length += it->second - 1;   //to make it even
            }
           
           if (!singleChar.empty()) length++;
            
        

        return length;
    }
};


int main(){
    Solution sol;
    string s = "AAbB";

    cout << "Length of possible palidrome of " << s << " is: " << sol.longestPalindrome(s) << endl;

    return 0;
}
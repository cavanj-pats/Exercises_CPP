//leet 5 longest palindromic substring

//leetcode submitted and accepted
/*
Runtime: 36 ms, faster than 70.68% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 21.2 MB, less than 47.35% of C++ online submissions for Longest Palindromic Substring.
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
struct substringPoints{
    int left;
    int right;
};
*/

bool palPal(string x);

class Solution {
public:
    string longestPalindrome(string s) {
        //if odd length take the middle three to start
        //if it can grow and be pali then grow it both sides
        //if even take the middle two and grow it  same as for odd
        //if the pali is on either end then grow from the end

        //if (palPal(s)) return s;

       // vector<substringPoints> SSP;
       // substringPoints ss;
        string max;
        int maxLen =0;

        //if the length is even try to find a pair of characters then grow 
        //if the length is odd try to find three characters and try to grow

        //this algorithm needs to find a palindrome of either size 2 or 3
        //then grow it from there to it's fullest extent
        //so starting subStr has to be 2 and ending subStr needs to be 3
        //then grow from there if and only if we find a palindrome

        int sSize = s.size();
        //int subStr = 2;
        
        if (sSize <=1) return s;
        if (sSize == 2 && s[0] != s[1]) return s.substr(0,1);

        for (int subStr=2; subStr < 4; ++subStr){
            for (int i = 0; i< sSize-subStr+1; i++){
                int j = i;
                int k = i+subStr-1;
                int l = subStr;
                while (j>=0 && k <sSize && s[j]==s[k]){
                    
                        //pali substring
                       // ss.left = i;
                        //ss.right = k;
                        //SSP.push_back(ss);
                        if (l > maxLen){
                            maxLen = l;
                            max = s.substr(j, l);
                        }
                        --j;
                        ++k;
                        l+=2;
                    
                }
                if (maxLen == sSize) return max;
                
                }
        
            
        }

        if (max == "" ) return s.substr(0,1);
        return max;
        
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
    string result;
    string test = "abcdcbe";

    result = sol.longestPalindrome(test);

    cout << "Longest palindromic substring of "<< test << " is " << result << endl;

    return 0;
}
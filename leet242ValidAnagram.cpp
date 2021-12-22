//leet 242 Valid Anagram

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//i jsut re-used teh canConstruct code from leet383RansomNote

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.size() != t.size()) return false;
        
        return canConstruct(s,t);
        
    }
    
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> noteMap;
        unordered_map<char, int> magMap;

        int maxSize = (ransomNote.size()>magazine.size() ? ransomNote.size() : magazine.size());

        for(int i = 0 ; i<maxSize; ++i){
            if(i<ransomNote.size())                
                noteMap[ransomNote[i]]++;
            
            if(i<magazine.size())
                magMap[magazine[i]]++;
            
        } 

        for(int i = 0; i<maxSize; ++i){
            if(i < ransomNote.size()){
              //  if(magMap.find(ransomNote[i]) == magMap.end() ) return false;  //need char that is not in magazine
                //if it gets here, the character is in magazine. 

                
                if(magMap[ransomNote[i]] < noteMap[ransomNote[i]])
                        return false;   //not enough characters in the magazine to write Note
            }
        }

        return true;
    }
    
};
//763 Partition Labels
//                     1/18/2022

/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct partition{
    int start;
    int length;
    std::string str;
};

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::unordered_map <char, int> charPartitionMap(s.size(),0);
        std::vector<int> result;
        int numPartitions = s.size();  //to start with
        

        for (int i=0; i<numPartitions; ++i){
            charPartitionMap[s[i]] = i;//store the max position
        }


        
    }
};
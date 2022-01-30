//leet 347 Top K most frequent elements

#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> intMap = {{1,0}, {2,0},{3,0},{4,0},{5,0},
                                        {6,0},{7,0},{8,0},{9,0},{0,0}};
       // unordered_map<int, int>:: iterator it;
        

       vector<int> result;
        for (int i=0; i<nums.size(); ++i){
            intMap[nums[i]]++;
        }

        
        
        

    return nums;
        
    }
};


int main(){
    Solution sol;
    vector<int> nums = {2,2,2,4,5,6,6};
    vector<int> result = sol.topKFrequent(nums, 2);

    return 0;
}
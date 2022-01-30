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
       //  **** I thought pre initialization was required but it is not required ***
       // *** we can directly start filling the map using the for loop shown below.

       // unordered_map<int, int> intMap = {{1,0}, {2,0},{3,0},{4,0},{5,0},
       //                                 {6,0},{7,0},{8,0},{9,0},{0,0}};
       // unordered_map<int, int>:: iterator it;
        
        unordered_map<int,int> intMap;
        unordered_map<int,int>::iterator it;

       vector<int> result;
        for (int i=0; i<nums.size(); ++i){
            intMap[nums[i]]++;
        }

        sort(intMap.begin(), intMap.end(), cmp);

        int count = 0;
        for(it = intMap.end(); it==intMap.begin();){
            //it = intMap.end();
         //   --it;
            intMap.erase(it);
            result.push_back(it->first);
            if (count++ == k) break;
            
        }
        
        
        

    return result;
        
    }

//function so we can compare two MAP elements
private:
    bool cmp(pair<int, int>& a,
         pair<int, int>& b)
    {
        return a.second < b.second;
    }



};


int main(){
    Solution sol;
    vector<int> nums = {2,2,2,4,5,6,6};
    vector<int> result = sol.topKFrequent(nums, 2);

    return 0;
}
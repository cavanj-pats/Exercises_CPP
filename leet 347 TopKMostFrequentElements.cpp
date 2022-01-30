//leet 347 Top K most frequent elements


/*
Success
Details 
Runtime: 16 ms, faster than 77.86% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 13.6 MB, less than 71.77% of C++ online submissions for Top K Frequent Elements.
*/

#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//this is from stackoverflow but is an idea I had so I am ok with using this code
//i changed name from less_second to gt_secomd because I changed operator to greater than
template <typename T1, typename T2>
struct gt_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       //  **** I thought pre initialization was required but it is not required ***
       // *** we can directly start filling the map using the for loop shown below.

       // unordered_map<int, int> intMap = {{1,0}, {2,0},{3,0},{4,0},{5,0},
       //                                 {6,0},{7,0},{8,0},{9,0},{0,0}};
       // unordered_map<int, int>:: iterator it;
        
        unordered_map<int,int> intMap;
      
       vector<int> result;
        int i = 0;
        int j = nums.size()-1;
        bool even = nums.size()%2 ==0 ? true : false ;
        while (i<j){
            intMap[nums[i]]++;
            intMap[nums[j]]++;
            ++i;
            --j;
        }
        if (!even) intMap[nums[i]]++;

        vector<pair<int, int> > mapcopy(intMap.begin(), intMap.end());
        sort(mapcopy.begin(), mapcopy.end(), gt_second<int, int>());
        int count = 0;
        for (auto m : mapcopy){
            result.push_back(m.first);
            if(++count == k) break;
        }
      

    return result;
        
    }


};


int main(){
    Solution sol;
    vector<int> nums = {2,2,2,4,5,6,6};
    vector<int> result = sol.topKFrequent(nums, 2);

    for(int i = 0; i<result.size(); ++i)
        cout <<  result[i] <<", ";


    cout << endl;   

    return 0;
}
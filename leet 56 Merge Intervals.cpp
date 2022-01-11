// merge overlapping vectors
//leet 56 Merge Intervals

//accepted by leetcode
//not very fast (faster than 10% which means slower than 90%)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printIntVector(std::vector<int> v);


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        vector<int> temp = {0,0};
        int size = intervals.size();
        if (size ==1) return intervals;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        
        while (i < size){
            if (i ==0){
                //initialize temp
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
            else if(temp[1] >= intervals[i][0] )
            {
                //merge
                if (temp[1] < intervals[i][1]){
                    temp[1] = intervals[i][1];
                }
                //don't need to worry about temp[0] if intervals is sorted

            }
            else {
                //no merge.  if no merge then push the temp onto result
                result.push_back(temp);
                //if (i < size-1) ++i;
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
            ++i;
            if (i == size) result.push_back(temp);
        }
        
        return result;
        
              
    }
};

void printIntVector(std::vector<int> v){
    std::cout << "[";
    for(int i = 0; i<v.size(); ++i){
        i==v.size()-1 ? std::cout << v[i] : std::cout << v[i] << ", ";
    }
    std::cout << "]";

}


int main(){
    vector<vector<int>> nums = {{1,3}, {0,1}, {3,10}, {15, 18}};
    Solution sol;
    vector<vector<int>> result = sol.merge(nums);

    cout << "[";
    for(auto n:nums){
        printIntVector(n);
        n == nums[nums.size()-1] ? std::cout <<"]" : std::cout << ", ";
    }
    std::cout << endl;

    cout << "[";
    for(auto n:result){
        printIntVector(n);
        n == result[result.size()-1] ? std::cout << "]" : std::cout << ", ";
    }
    std::cout << endl;


}
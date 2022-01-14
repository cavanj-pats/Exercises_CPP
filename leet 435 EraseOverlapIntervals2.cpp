//leet 435 Remove NonOverlapping Intervals

//use Greedy Algorithm approach
//submited and accepted by leetcode


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


//used to sort by finish dates
bool comp(vector<int>& a, vector<int>& b){
    return a[1]<b[1];
}


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        //vector<interval> overlappers;
        vector<vector<int>> candidates;
        vector<int> prev = {0,0};
        
        int counter=0;
        int iSize = intervals.size();
        
        
        if(intervals.size() <= 1) return 0;  //there are no overlapping intervals

        sort(intervals.begin(), intervals.end(), comp);
        //set the previous item
        prev[0] = intervals[0][0];
        prev[1] = intervals[0][1];

        for (int i = 1; i<iSize ; ++i){
            if (intervals[i][0] >= prev[1]){
                candidates.push_back(prev);
                prev[0]=intervals[i][0];
                prev[1] = intervals[i][1];
            }
        }

        return iSize - candidates.size()-1;

        
        
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
    vector<vector<int>> nums = {{1,100},{11,22},{1,11},{2,12}};// {{1,2},{2,3},{3,4},{1,3}};
    //{{1,3}, {0,2}, {2,10}, {15, 18}};
    Solution sol;
    //vector<vector<int>> result = sol.merge(nums);

    cout << "[";
    for(auto n:nums){
        printIntVector(n);
        n == nums[nums.size()-1] ? std::cout <<"]" : std::cout << ", ";
    }
    std::cout << endl;

    cout << "Overlapping Intervals: " << sol.eraseOverlapIntervals(nums) << endl;
    

    return 0;
}
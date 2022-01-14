//leet 435 Remove NonOverlapping Intervals

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct interval{
    int start;
    int end;
    int idx;
};

bool overlap(interval a, interval b){
    //overlay
    if (a.start == b.start && a.end == b.end) return true;
    //overlap left
    if (b.start < a.start && b.start < a.end) return true;  //a (1,3) b 0,2
    if (a.start < b.start && b.start < a.end) return true;   //a (0,3) b(1,2)

    //b fits inside a
    if (a.start < b.start && b.end < a.end) return true;
    if (b.start < a.start && a.end < b.end) return true;

    return false;


}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        vector<interval> temp;
        interval a, b;

        
       for (int i = 0; i<intervals.size()-1; ++i){
           for (int j = i+1; j<intervals.size(); ++j){
            a.start = intervals[i][0];
            a.end = intervals[i][1];
            a.idx = i;
            b.start = intervals[j][0];
            b.end = intervals[j][1];
            b.idx = j;
            if(overlap(a,b)) temp.push_back(b);
           }
            

        }

        //need to remove duplicates from vetor temp
        //delete any duplicates
       // sort(temp.begin()->idx, temp.end()->idx);
        for (int i = 1 ; i<temp.size(); ++i){
            if (temp[i-1].idx == temp[i].idx){
                temp.erase(temp.begin()+i);
            }
        }
        return temp.size();
        
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
    vector<vector<int>> nums =  {{1,2},{2,3}}; //,{3,4},{1,3}};
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
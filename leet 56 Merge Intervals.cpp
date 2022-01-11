// merge overlapping vectors


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
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < size; ++i){
                           
            if (i < size-1){
                if (intervals[i][1] >= intervals[i+1][0]){ 
                    //merge
                    //take the smallest start and longest end
                    if(intervals[i][0] < intervals[i+1][0])
                        temp[0] = intervals[i] [0];
                    else
                        temp[0] = intervals[i+1] [0];
                    
                    if(intervals[i][1] < intervals[i+1][1])
                        temp[1] = intervals[i+1] [1];
                    else
                        temp[1] = intervals[i][1];
                    
                    
                    result.push_back(temp);
                    //temp.clear();
                    ++i;
                }
                else {
                    temp[0] = intervals[i] [0];
                    temp[1] = intervals[i] [1];
                    result.push_back(temp);

                }
            }
            else if (i < size)
            {
                temp[0] = intervals[i] [0];
                temp[1] = intervals[i] [1];
                result.push_back(temp);
                //temp.clear();
            }
            
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
    vector<vector<int>> nums = {{1,3}, {0,0}, {3,10}, {15, 18}};
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
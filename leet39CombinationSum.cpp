//39. leet  Combination Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combineAll_rec(vector<int>&, int , int , int , vector<vector<int>>& ,vector<int>& );

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> output;
        vector<int> result;
    
        //sort(candidates.begin(), candidates.end());

        combineAll_rec(candidates, target, 0,0,output,result);
        return output;
    }
};

void combineAll_rec(vector<int> &nums, int target, int start, int runningSum, 
        vector<vector<int>>& output,vector<int>& result    ){    
    
    int currSum=runningSum;

    if (runningSum == target){
        output.push_back(result);
    }
    else if (runningSum > target){
        return;   //never gets here
    }
    else {
        for (int i = start; i<nums.size(); ++i){
            currSum =currSum + nums[i];
            if (currSum <= target){
                result.push_back(nums[i]);
                combineAll_rec(nums, target,i,currSum,output,result);
                result.pop_back();
                currSum = runningSum;

            }
            else{
                currSum = currSum - nums[i];
                //return;
            }
        }
    }
}
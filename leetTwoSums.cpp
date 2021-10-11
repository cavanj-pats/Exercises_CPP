//1.TwoSum - LeetCode

#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx;
        vector<int> ans;
        int a1;
        bool solutionFound = false;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<= target) 
                idx.push_back(i);
        }
        
        for(int i=0; i<idx.size(); i++){
            for(int j=0; j<idx.size(); j++)
                if((j!=i && nums[i]+ nums[j] == target) && !solutionFound){
                    ans.push_back(i);
                    ans.push_back(j);
                    solutionFound = true;
                }
        }
        return ans;
    }
};



int main (){
    Solution sol;
    
    vector<int> nums, ans;

    nums.push_back(0);
    nums[1]=3;
    nums[2]=4;
    nums[3]=0;

    ans = sol.twoSum(nums, 0);

    for(int i=0; ans.size(); i++)
        cout << ans[i] << ", " ;
    
     cout << endl;


    return 0;

}
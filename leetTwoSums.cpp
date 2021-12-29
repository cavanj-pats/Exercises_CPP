//1.TwoSum - LeetCode

#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx; //this is a vector of the only possible indexes in nums that might be a solution
        vector<int> ans;
        bool solutionFound = false;
       

        ans.clear();

       
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++)
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
    
    vector<int> nums;
    vector<int> ans;

    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(90);

   // cout << nums.size() << endl;
    ans.clear();

    ans = sol.twoSum(nums, 0);

    for(int i=0; i<ans.size(); i++){
        if(i<ans.size()-1) 
            cout << ans[i] << ", " ;
        else
            cout << ans[i];
    }
    
     cout << endl;


    return 0;

}
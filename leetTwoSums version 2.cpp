//1.TwoSum version two   modified logic not tested- LeetCode

#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
        vector<int> ans;
        bool solutionFound = false;
      

       
        ans.clear();
        sort(nums.begin(), nums.end());
        int x = 0;
        int y=nums.size()-1;
       
        while (x < y){
            if(nums[x] + nums[y] <  target){
                ++x;
            }
            else if (nums[x]+ nums[y] >target){
                --y;
            } else{
                ans.push_back(nums[x]);
                ans.push_back(nums[y]);
                solutionFound = true;
                while (x < y && (nums[x] == nums[x+1])) ++x;
                while (x < y && (nums[y] == nums[y-1])) --y;
                ++x; --y;
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
    nums.push_back(-90);

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
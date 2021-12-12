//45 Jump Game II
//minimum number of jumps to get to last index

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
       
        vector <int> prefixSum (nums.size()-1,0);
        int ans =0;

        
        for(int i=0; i<nums.size(); ++i){
            if (i==0) 
                prefixSum[i] = nums[i];
            else
                prefixSum[i]= prefixSum[i-1]+nums[i];

            ans++;    
            if(prefixSum[i]>=nums.size()-1) break;
            
        }       

        return ans;

    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,0,3,1,2,4};
    cout << "Min Jumps: " << sol.jump(nums) << endl;

    return 0;
}
//leet 53 largest contiguous subarray

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=nums[0];
        int length = nums.size();
        //int maxIdx=0;  //index of MaxPrefixSum
        //int maxPreVal=nums[0];  //starting value for maxPrefixValue
        //int maxPostIdx=length-1;
        //int maxPostVal = nums[length-1];

        //vector<int> prefixSum(length,0);  //from first index to last
        //vector<int> postfixSum(length, 0);  //from last index to first
        //prefixSum[0] = nums[0];
        //postfixSum[length-1] = nums[length-1];

        for(int i=1; i<length; i++){
            sum = max(sum + nums[i], nums[i]);
            ans = max(ans, sum);

        }
        
        /*
        for(int i=1; i<length;++i){
            prefixSum[i] = prefixSum[i-1]+nums[i];
            postfixSum[length-i-1] = postfixSum[length-i] + nums[length-i-1];

            if (prefixSum[i] > maxPreVal){ 
                maxIdx = i;
                maxPreVal = prefixSum[i];
            }
            if (postfixSum[length-i-1]> maxPostVal){
                 maxPostIdx = length-i-1;
                 maxPostVal = postfixSum[length-i-1];
            }

         }
         for (int i=maxPostIdx; i<maxIdx+1; ++i){
                ans +=nums[i];
         }
         */

       return ans;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}
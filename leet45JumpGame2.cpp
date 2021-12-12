//45 Jump Game II
//minimum number of jumps to get to last index

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
       //code pasted after struggling for about an hour
       //https://leetcode.com/problems/jump-game-ii/discuss/18019/10-lines-C%2B%2B-(16ms)-Python-BFS-Solutions-with-Explanations

        int i = 0, n = nums.size(), step = 0, end = 0, maxend = 0;
        while (end < n - 1) {
        	step++;
            for (;i <= end; i++) {
            	maxend = max(maxend, i + nums[i]);
                if (maxend >= n - 1) return step;
            }
            if(end == maxend) break;
            end = maxend;
        }
        return n == 1 ? 0 : -1;


    }
};

int main(){
    Solution sol;
    vector<int> nums = {3,2,1,0,4};
    cout << "Min Jumps: " << sol.jump(nums) << endl;

    return 0;
}
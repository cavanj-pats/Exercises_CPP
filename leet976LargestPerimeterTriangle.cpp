//976. Largest Perimiter of Triangle
//if not a triangle or zero area return 0


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i = 0; i<=nums.size()-3; ++i){
            if (nums[i] <nums[i+1]+nums[i+2])
                return nums[i]+nums[i+1]+nums[i+2];
        }
        return 0;
    }
};

/*
Success
Details 
Runtime: 28 ms, faster than 98.19% of C++ online submissions for Largest Perimeter Triangle.
Memory Usage: 21.9 MB, less than 72.49% of C++ online submissions for Largest Perimeter Triangle.
*/

int main(){
    Solution sol;
    vector<int> n = {2,3,9,4,1};
    cout << sol.largestPerimeter(n) << endl;

    return 0;
}
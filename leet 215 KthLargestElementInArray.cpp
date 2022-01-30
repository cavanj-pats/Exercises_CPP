//leet 215 Kth largest element in an array

/*
Success
Details 
Runtime: 20 ms, faster than 22.40% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.1 MB, less than 58.46% of C++ online submissions for Kth Largest Element in an Array.
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int counter =1;
        int currMax = *max_element(nums.begin(), nums.end());

        sort(nums.begin(), nums.end());

        int i = nums.size()-1;
        while (counter < k && i>0){
           --i;
          // if (nums[i] < currMax){
                counter++;
              //  currMax = nums[i];
            //}
            
        }

        return nums[i];
    }
};
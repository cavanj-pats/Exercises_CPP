//leet 466 hamming distance sum

/*
For each bit position 1-32 in a 32-bit integer belonging to the array, we count the number of integers 
in the array which have that bit set.

Then, if there are n integers in the array and k of them have a particular bit set and (n-k) do not, 
then that bit contributes nx(n-k) to the hamming distance. (Because for each of the 'k' numbers, we 
have 1 of the (n-k) numbers, that have a different bit and the number of ways to select 1 from k 
and (n-k) numbers is (kC1)x((n-k)C1)
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        //from _geeky_coder_ on leetcode
        int n=nums.size(), ans=0;
        for(int i=0;i<32;i++){
            int count=0; //Count of the no.of elements that have the 'i'th bit set
            for(int k=0;k<n;k++){
                count += (nums[k]>>i)&1; //if a number has this bit set it will return 1 if not it will return 0
                //so this counts the total bits in teh array that are different.
            }
            ans += count*(n-count);  //i think this is the combination of bits getting folded into answer
        }
        return ans;
           
    }
};



int main(){
    Solution sol;
    vector<int> nums = {4,14,4};    
    cout<< "Hamming {4, 14, 4}= "<< sol.totalHammingDistance(nums)<< endl;

    return 0;
}
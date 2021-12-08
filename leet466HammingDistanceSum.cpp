//leet 466 hamming distance sum

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
       vector<vector<int>> distancePairs;
       vector<int> temp;
       int ans=0;

       pairCombinations_rec(distancePairs, 0, 1, nums, temp);

       for(auto pair: distancePairs){
           ans+=hammingDistance(pair[0],pair[1]);

       } 

       return ans;

    }
    



    int hammingDistance(int x, int y) {
        int hd=0;

        for (int i=0; i<32; ++i){
            if (((x>>i) & 1) != ((y>>i) & 1))            
                hd++;
        }
        return hd; 
    }

    void pairCombinations_rec(vector<vector<int>> &distancePairs, int idx1, int idx2, vector<int> &nums, vector<int> &temp){
        if(idx1==nums.size()-1) return;
        temp.push_back(nums[idx1]);
        temp.push_back(nums[idx2]);
        distancePairs.push_back(temp);
        temp.clear();

        if ( idx2 == nums.size()-1)
            pairCombinations_rec(distancePairs, idx1+1, idx1+2,nums, temp);
        if(idx2<nums.size()-1)
            pairCombinations_rec(distancePairs, idx1, idx2+1, nums, temp);

        return;

    }


};

int main(){
    Solution sol;
    vector<int> nums = {4,14,4};    
    cout<< "Hamming {4, 14, 4}= "<< sol.totalHammingDistance(nums)<< endl;

    return 0;
}
//350. Intersection of Two Arrays II


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int m=nums1.size();  //arbitrarily choose
        int n=nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;


        while (i<m && j < n){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                ++i;
                ++j;
            } else if(nums1[i]< nums2[j]){
                ++i;
            } else{
                ++j;
            }
            
        }

        return ans;
    }
};




int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
     vector<int> ans;
    Solution sol;

    ans=sol.intersect(nums1, nums2);
    cout << "[";
    for(int n:ans){
         cout << n ;
        if (n != ans.back()) cout << ", ";
       
    }
    cout <<"]";

    return 0;
}

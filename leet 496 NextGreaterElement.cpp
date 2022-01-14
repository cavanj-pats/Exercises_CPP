//496. next greatest element.   leetcode
#include <iostream>
#include <vector>

using namespace std;


///actually sorting the array is not the right thing to do based on the problem definition.
//since all of nums1 are in nums2,  we must find the element from nums1 in nums2 then index one to the right
//if at the end or if no match,  return -1

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        int temp, idx, x, y;
        bool isFound;
  

        for(int i=0; i<nums1.size();i++){
            isFound = false;
            for(int k=0; k<nums2.size(); k++){
                if(nums1[i]== nums2[k] && !isFound){
                    for(int j=k+1; j<nums2.size(); j++)
                        if(nums2[j]>nums1[i] && !isFound){
                            isFound = true;
                            ans.push_back(nums2[j]);
                        }

                    
                }

            
            }
            
            if(!isFound)
                ans.push_back(-1);
           
        }    
            return ans;  
    }
};



int main(){
    vector <int> nums1 = {2,4};
    vector <int> nums2 = {1,2,3,4};

    Solution sol;

    vector <int> temp = sol.nextGreaterElement(nums1, nums2);

    for(int i=0; i<temp.size();i++)
        cout << temp[i] << "\t";

    cout << endl;
}
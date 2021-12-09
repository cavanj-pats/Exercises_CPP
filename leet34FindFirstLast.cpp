//leet34 find first and last in sorted array

#include <iostream>
#include <vector>

using namespace std;

int binary_search(int, vector<int>&, int);

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx=0;
        int first =0;
        int last =0;
        vector<int> ans;
        
        if(nums.size() == 1 && nums[0] == target){
            ans.push_back(0);
            ans.push_back(0);
            return ans;
        }

        idx = binary_search(target, nums, nums.size()-1);
        if (idx == -1) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
            
        }
        first = idx;
        
        for(int i = first ; i> -1 ; --i){
             if(nums[i] == target ) first = i;
             if(nums[i] < target) break;
        }
        ans.push_back(first);
        
        last = idx;
        for (int i = last; i < nums.size(); ++i ){
            if(nums[i] == target) last = i;

            if(nums[i] > target) break;    
        }
        
        ans.push_back(last);
        
        return ans;
        
    }
};


int binary_search( int val, vector<int>& srtArr, int srtArrSize){
    int low, high, mid;
    int ind;
    int counter=0;
    bool found = false;
    low = 0;
    high = srtArrSize;
    //if (srtArrSize == 0 && srtArr[0]== val) return 0;

    while (( found == false) && (low<=high) ){
       // counter++;
        mid = (low + high)/2;
        if (srtArr[mid] == val){
            ind = mid;
            found = true;
            return ind;   //just stop searching
        }
        else if (val < srtArr[mid])
            high = mid -1;
        else //val > srtArr[mid]
            low = mid + 1;

        
    }
    
    if (found == true)
        return ind;
    else
        return -1;
    
   //return counter;

      
}


int main(){
    Solution sol;
    vector<int> nums = {10,10};
    
    cout<< "Nums 5,7,7,8,8,10 " ;
    vector<int> ans= sol.searchRange(nums, 10);
    for (int i=0; i<ans.size(); ++i){
        cout << ans[i] << ", ";
    }
         cout << endl;
    
    return 0;

}
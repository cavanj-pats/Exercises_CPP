//leet 334 increasing triplet sequence

//submited and accepted.  Not very good.  912ms faster than 5%
//memore less than 15%
//but it worked

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        if ((temp.back() - temp.front()) < 2) return false;
        
        int length = nums.size();
        
        for (int i = 0 ; i<length-2 ; ++i){
            for(int j = i+1; j<length-1; ++j){
                while (nums[j]<=nums[i] && j<length-2) ++j;
              
                // if(nums[j] <= nums[j-1] && j<length-2) ++j
                    
            
                    for (int k=j+1; k< length; ++k){
                        if(nums[i] < nums[j] && nums[j] < nums[k]) return true;
                        
                    }
            }
        }
         /*   
            int j = i+1;
            int k = length -1;
            while (j < length-1 && j < k){
                    if(nums[i] < nums[j] && nums[j] < nums[k]) return true;
                
                    if(nums[j] < nums[i]){
                        //must move j
                        ++j;  //index at least once
                        while (j < length-1 && nums[j-1] >= nums[j]){
                            ++j;
                        }
                    } else if( j<k && nums[k-1] > nums[k]){
                        --k;
                        
                    }
                
                    
                
            }
                
        }
    */
        
        return false;
            
        
        
    }
};
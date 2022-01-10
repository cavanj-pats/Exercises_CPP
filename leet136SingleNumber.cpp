///leet136SingleNumber.cpp

//Data Structures  Study Plan II   
//  1/9/2022


//this was submitted and accepted.  
//The best soltion called for using the XOR operator ^= which would either add  or remove an item from a result
//need to study this.

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        
        map <int, int> result;
        
        int i = 0;
        int j = nums.size()-1;

         if (j ==0) return nums[0]; 
        
        while (i < j){
            result[nums[i]]+=1;
            result[nums[j]]+=1;
            i++;
            j--;
        }
        if ((nums.size()-1) %2 != (nums.size()-1)/2) result[nums[i]]+=1;
        
            for (std::map <int, int> ::iterator it = result.begin(); it!=result.end(); ++it){
                if(it->second ==1){
                    return it->first;
                }
            }
        


        return 0;



        
    }
    
};

int main(){
    Solution sol;
    vector <int> nums = {1,2,3,4,1,2,3};

    cout<< "Item that was not duplicated: " <<sol.singleNumber(nums)<< endl;


    return 0;
}
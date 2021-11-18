//216 Combination Sum III
// similar to other CombinationSUm problems


/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice,
 and the combinations may be returned in any order.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void combineAll_rec(vector<int>&, int , int , int , int, vector<vector<int>>& ,vector<int>&  );

class Solution{
public:
vector<vector<int>> combinationSum3(int k, int n){
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> output;    
        vector<int> result;
        
        combineAll_rec(candidates, n, 0,0,k, output,result);
        //return removeDuplicates(output);
        return output;
    }

};


    //recursively go through the source vector for sums
    //recursion works perfect to make sure all values are covered
    //it is really quite clever how this works.  need to really think about it
 void combineAll_rec(vector<int>& nums, int target, int start, int runningSum, 
       int k, vector<vector<int>>& output,vector<int>& result ){    
    
    
    if ((start >= nums.size() || runningSum >= target) ){
       if (runningSum == target && result.size() == k)
            output.push_back(result);
       
       return; 
    }
    
    result.push_back(nums[start]);
    combineAll_rec(nums, target,start+1,runningSum + nums[start], k,output,result);
    result.pop_back();
    while ((start < nums.size()-1) && (nums[start] == nums[start+1]) )
        start++;
    combineAll_rec(nums, target, start+1, runningSum,k, output,result);

        
    }

   


int main(){
   // vector<int> nums = {10,1,2,7,6,1,5};
   //vector<int> nums = {2,5,2,1,2};
   //vector<int> nums ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //int target = 5;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum3(3, 9);

    
    for (auto a: ans){
        cout << "[" ;
        for(int i=0; i<a.size(); ++i){
            if(i == a.size()-1){ 
                cout << a[i];
            }
            else{
                cout << a[i]<< ", " ;
            }
        }
        cout<< "]" << endl;
    }

    return 0;
}

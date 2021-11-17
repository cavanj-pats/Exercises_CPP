// https://www.educative.io/m/find-all-sum-combinations
//
//Find All Sum Combinations  modified for find unique combinations
//selfStudyFindAllSumCombinations.cpp  11/16/2021

//in this version duplicate results are not allowed
//and each candidate can only be used once in a result set
//
//need to use map<int, map<int, int>> for teh result set
//so that we can use find for each possible result entry 
//to see if it is already there

/*
1. Hint was use recursion and two lists

if running sum == target then make sure to return solution
if running sum is < target add next number
if running sum > target then we don't need to look any more

use of duplicate numbers is accepted   i.e. nums {2, 3, 5,8} target =8  one sol'n [2,2,2,2]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



vector<vector<int>> allSumCombos(vector<int>, int);
void combineAll_rec(vector<int>&, int , int , int , vector<vector<int>>& ,vector<int>&  );
bool isDuplicate(vector<vector<int>> &, vector<int>&);


vector<vector<int>> allSumCombos(vector<int> candidates, int target){
    vector<vector<int>> output;
    vector<int> result;
    int res=0;
   
    //i needed to add this as my code only works when sorted
    
    sort(candidates.begin(), candidates.end());
    if(candidates[0] == candidates[candidates.size()-1] && candidates.size()>1){
        //all the data is the same.
        if(target/candidates[0] >candidates.size()) return output;

        for (int i=0; i<target/candidates[0]; ++i){
            result.push_back(candidates[i]);
            res= res + candidates[i];
        }
        if (res != target) return output;
        output.push_back(result);
        return output;
        
    }
    
    combineAll_rec(candidates, target, 0,0,output,result);
    //return removeDuplicates(output);
    return output;
};


    //recursively go through the source vector for sums
    //recursion works perfect to make sure all values are covered
    //it is really quite clever how this works.  need to really think about it
 void combineAll_rec(vector<int>& nums, int target, int start, int runningSum, 
        vector<vector<int>>& output,vector<int>& result ){    
    
    int currSum=runningSum;
    int counter = 0;

    if (runningSum == target){
        sort(result.begin(),result.end());
        if(output.size()==0 ) output.push_back(result);
        if(!isDuplicate(output, result)){
         output.push_back(result);   
        }
        
    }
    else if (runningSum > target){
        return;   //never gets here
    }
    else {
        for (int i = start; i<nums.size(); ++i){
            //if ((i<nums.size()-1) && (nums[i] == nums[i+1])) continue;
            currSum =currSum + nums[i];
            if (currSum <= target){
                result.push_back(nums[i]);
                
                    combineAll_rec(nums, target,i+1,currSum,output,result);
                
                result.pop_back();
                
                currSum = runningSum;

            }
            else{
                 currSum = currSum - nums[i];//see if perhaps there is another solution
                //return;
            }
        }
    }

   
               
            
        
            
        

}

bool isDuplicate(vector<vector<int>> & output, vector<int> &result){
    int counter;
    bool ans = false;
    if(output.size()<1) return ans;
    for(auto o: output){
        counter =0;
        if(o.size() == result.size()){
            for(int i=0; i<o.size(); ++i){
                if(o[i] == result[i]) counter++;
            }
            if (counter == o.size()) return true;
        }    
        
    }
     return ans;
}



int main(){
   // vector<int> nums = {10,1,2,7,6,1,5};
   //vector<int> nums = {2,5,2,1,2};
   vector<int> nums ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target = 30;
    vector<vector<int>> ans = allSumCombos(nums, target);

    
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

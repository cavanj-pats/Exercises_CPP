// https://www.educative.io/m/find-all-sum-combinations
//
//Find All Sum Combinations
//selfStudyFindAllSumCombinations.cpp  11/11/2021

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

using namespace std;



vector<vector<int>> allSumCombos(vector<int>, int);
void combineAll_rec(vector<int>&, int , int , int , vector<vector<int>>& ,vector<int>& );


vector<vector<int>> allSumCombos(vector<int> nums, int target){
    vector<vector<int>> output;
    vector<int> result;
   
    //i needed to add this as my code only works when sorted
    //sort(nums.begin(), nums.end());


    combineAll_rec(nums, target, 0,0,output,result);
    return output;
};


    //recursively go through the source vector for sums
    //recursion works perfect to make sure all values are covered
    //it is really quite clever how this works.  need to really think about it
 void combineAll_rec(vector<int> &nums, int target, int start, int runningSum, 
        vector<vector<int>>& output,vector<int>& result    ){    
    
    int currSum=runningSum;

    if (runningSum == target){
        output.push_back(result);
    }
    else if (runningSum > target){
        return;   //never gets here
    }
    else {
        for (int i = start; i<nums.size(); ++i){
            currSum =currSum + nums[i];
            if (currSum <= target){
                result.push_back(nums[i]);
                //if below was i+1 the value of i would not repeat
                //if i>..size, then loop would not run
                combineAll_rec(nums, target,i,currSum,output,result);
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



int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
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

// https://www.educative.io/m/find-all-sum-combinations
//
//Find All Sum Combinations  modified for find unique combinations
//selfStudyFindAllSumCombinations.cpp  11/16/2021

//in this version duplicate results are not allowed
//and each candidate can only be used once in a result set
//

/*
1. Hint was use recursion at two levels


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
    
   
    combineAll_rec(candidates, target, 0,0,output,result);
    //return removeDuplicates(output);
    return output;
};


    //recursively go through the source vector for sums
    //recursion works perfect to make sure all values are covered
    //it is really quite clever how this works.  need to really think about it
 void combineAll_rec(vector<int>& nums, int target, int start, int runningSum, 
        vector<vector<int>>& output,vector<int>& result ){    
    
    
    if (start >= nums.size() || runningSum >= target){
       if (runningSum == target)
            output.push_back(result);
       
       return; 
    }
    
    result.push_back(nums[start]);
    combineAll_rec(nums, target,start+1,runningSum + nums[start],output,result);
    result.pop_back();
    while ((start < nums.size()-1) && (nums[start] == nums[start+1]) )
        start++;
    combineAll_rec(nums, target, start+1, runningSum,output,result);

        
    }

   


int main(){
   // vector<int> nums = {10,1,2,7,6,1,5};
   vector<int> nums = {2,5,2,1,2};
   //vector<int> nums ={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    int target = 5;
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

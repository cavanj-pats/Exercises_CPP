//LeetCode 15. 3Sum

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            int i=0;
            int z=0;
            int k=0;
            bool temp1=false;
            bool temp2=false;

            vector<vector<int>> a;
            vector<int> two;
            vector<int> temp;

            for(auto num: nums){
                for(int j=0; j<nums.size(); j++){
                    if(j!=i ) temp.push_back(nums[j]);
                    
                }
                two = twoSum(temp, -1*num);
                if(two.size()!=0){
                    two.push_back(num);  //i think it is ok that it is in the back
                    a.push_back(two);
                    
                }

                temp.clear();
                i++;
            }

        return a;
         
    }

private:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> idx; //this is a vector of the only possible indexes in nums that might be a solution
        vector<int> ans;
        bool solutionFound = false;
       /*
        for(int i=0; i<nums.size(); i++){
            //if(nums[i]<= target)  cannot use for negative numbers
                idx.push_back(i);
        }
        */

        ans.clear();

       
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++)
                if((j!=i && nums[i]+ nums[j] == target) && !solutionFound){
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    solutionFound = true;
                }
        }
        return ans;
    }
};


int main(){
    vector <int> a = {2,0,-1,1,5,-1};
    vector<vector<int>> ans;
    Solution sol;
    ans = sol.threeSum(a);
    for(auto x: ans){
        for(auto b: x){
            cout << b <<", ";
        }
        cout << endl;
    }




    return 0;
}
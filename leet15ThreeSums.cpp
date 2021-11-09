//LeetCode 15. 3Sum

#include <iostream>
#include <vector>
#include <bits/stdc++.h> //needed to use sort function.

///need a case for all zeros;

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            int i=0;
            int j=nums.size()-1;

            int z=0;
            int k=0;
            bool allZeroes=true;
            bool temp2=false;

            vector<vector<int>> a;
            vector<int> two;
            vector<int> temp;
            
            if (nums.empty()) return a;
            if (nums.size()==1 && nums[0] == 0) return a;
            if (nums.size()<3) return a;
            
            for(auto num: nums){
                if(num != 0) allZeroes = false;
                if(!allZeroes) break;
            }    
            
            if (nums.size() == 3) {
                if (allZeroes){
                    temp = {0,0,0};
                    a.push_back(temp);
                    return a;
                }
                else
                    if(nums[0]+nums[1]+nums[2] == 0){
                        temp.push_back(nums[0]);
                        temp.push_back(nums[1]);
                        temp.push_back(nums[2]);
                        a.push_back(temp);
                        return a;
                    }
                else
                    return a;

            }
            if (allZeroes){
                temp = {0,0,0};
                a.push_back(temp);
                return a;
            }

            if(nums.size()%2 == 0)
                z=nums.size()/2;
            else
                z=nums.size()/2+1;

            

            sort(nums.begin(), nums.end());
            //
            while (k < nums.size()-2 ){
                if(k==0 || (k>0 && nums[k]!=nums[k-1])){
                    i=k+1; j=nums.size()-1;
                    while (i<j){
                        temp.clear();
                        if(nums[i] + nums[j] == -1*nums[k]){
                            temp.push_back(nums[k]);
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            a.push_back(temp);

                            //avoid duplicate solution (sorted vector)
                            while (i <j && nums[i] == nums[i+1])
                                i++;
                            //avoid duplicate solution
                            while (i<j && nums[j-1] ==  nums[j]) 
                                j--;
                            
                            i++; j--;  //moves to next index that has not already been checked
                        }
                        else if(nums[i] + nums[j] < -1*nums[k]){
                            i++;
                        }
                        else{
                            j--;
                        }
                    }
                }
                k++;
            }        
              
        return a;
   
    }


};


int main(){
    //vector <int> a = {2,0,-1,1,5,-1};
   // vector <int> a = {-1,0,1,2,-1,-4};
  // vector <int> a = {-1, 0, 1};
    //vector <int> a = {0,0,0,0};
    //vector <int> a = {-2,0,1,1,2};
    //vector <int> a = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    vector <int> a = {0,-4,-1,-4,-2,-3,2};
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
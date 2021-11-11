//LeetCode 18. 4Sum Closest

#include <iostream>
#include <vector>
#include <algorithm> //needed to use sort function.
#include <cmath>
#include <math.h>

///need a case for all zeros;

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
            // 3<= nums.length <= 1000
            //-1000 <= nums[i] <= 1000
            //-10^4  <= target <= 10^4

           
            vector<vector<int>> ans;
            vector<int> temp;
            long long temp1;
            long long temp2;
            long long temp3;
            int targetRemaining;
            bool isDuplicate ;
            sort(nums.begin(), nums.end());

           
            int z = nums.size();
            if (z<4) return ans;

            for (int i= 0; i<z-3; i++){
                if(i>0 && nums[i]==nums[i-1])
                {
                //    continue;
                }
                
                

                for (int j= i+1; j<z-2 ;j++)
                {
                    if( j>i+1 && j<z && nums[j] == nums[j-1])
                    { 
                      //  continue;
                    }
                    temp2 = nums[i]+nums[j];
                    //temp2 +=nums[j];
                    if(i==1 & j ==2) 
                    {
                        targetRemaining = 1;
                    }

                    int k = j+1;
                    int n = z-1;
                    while (k<n)
                    {
                    //for (int k= j+1; k<z-1; k++){
                       
                        temp1 = temp2;
                        temp3=target-temp1;

                        if(k<n && nums[k]+nums[n] < temp3)
                        {
                            k++;
                            //continue;
                        }
                        else if(k<n && nums[k]+ nums[n] > temp3)
                        {
                            n--;
                           // continue;
                           
                        }
                        else
                        {
                           temp1+=nums[k] + nums[n];
                          // temp1+=nums[n];  
                                               
                            //temp2+=nums[k];
                            //temp2+=nums[n];
                            if(temp1 > pow(2,31) || temp1< pow(-2,31)-1)
                            {
                                continue;
                            }
                            //temp2 = nums[i] + nums[j] + nums[k] + nums[n];
                           // if (temp2 == target){
                            isDuplicate = false;    
                            temp.clear();
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            temp.push_back(nums[n]);
                            sort(temp.begin(), temp.end());
                            
                            if(ans.size()>0)
                            {
                                for(auto a: ans)
                                {
                                    if (a == temp)
                                    { 
                                        isDuplicate=true;
                                        break;
                                    }
                                }
                            }
                            if (!isDuplicate)
                            {
                                 ans.push_back(temp);
                                 k++; n--;   //do this after a solution
                            }
                            else
                            {
                               k++; //picked arbitrarily
                                //there is a duplicate
                               /*   while(k>j+1 && k<n && nums[k] == nums[k+1])
                                {
                                    k++;
                                }

                                while(n>k+1 && k<n && nums[n] == nums[n-1])
                                {
                                   n--;                                    
                                } */

                            }
                        }
                    }             
                    
                }
            }              
        return ans ;   
    }
};


int main(){
    //vector <int> a = {2,0,-1,1,5,-1};
   // vector <int> a = {-1,0,1,2,-1,-4};
  // vector <int> a = {-1, 0, 1};
    //vector <int> a = {0,0,0,0};
    //vector <int> a = {-2,0,1,1,2};
    //vector <int> a = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    //vector <int> a = {2,2,2,2,2};
    //vector <int> a = {-3,-2,-5,3,-4};
    //vector <int> a = {1,0,-1,0,-2,2};
    vector <int> a = {-3,-2,-1,0,0,1,2,3};
//[-5,5,4,-3,0,0,4,-2]   4
//vector <int>{1000000000,1000000000,1000000000,1000000000}    0
  //  vector <int> a = {1000000000,1000000000,1000000000,1000000000};
 //   vector <int> a = {0,0,0,0};
    int target = 0;
    vector<vector<int>> ans;
    Solution sol;
    ans = sol.fourSum(a, target);
    cout << "[ " ;
    for(auto x: ans){
        for(auto b: x){
            cout << b <<", ";
        }
        cout << endl;
    }
    /*
    for(auto z: a){
        cout << z << ", "; 
    }
        cout << " ] target: "<< target <<"= " << ans <<  endl;
    */




    return 0;
}
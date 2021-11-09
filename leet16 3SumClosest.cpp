//LeetCode 16. 3Sum Closest

#include <iostream>
#include <vector>
#include <bits/stdc++.h> //needed to use sort function.
#include <cmath>

///need a case for all zeros;

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
            // 3<= nums.length <= 1000
            //-1000 <= nums[i] <= 1000
            //-10^4  <= target <= 10^4


            //**** need to handle neg target and positive result and vice versa
            
           // int i=0;
           // int j=nums.size()-1;
          //  int k = 0;
            int ans;
            int temp;
            int temp2;
            
            //sort(nums.begin(), nums.end());

            if(nums.size() ==3) return nums[0]+nums[1]+nums[2];
            
            int z = nums.size();
            for (int i = 0; i<z-2; i++){
                for (int j = i+1; j<z-1; j++){
                    for (int k= j+1; k<z; k++){
                        if(i==0 && j ==1 && k==2){
                            temp = nums[i] + nums[j] + nums[k];
                        }
                        else{
                            temp2 = nums[i] + nums[j] + nums[k];
                            if(target <0)
                                if ((target-temp) < (target - temp2)) temp = temp2;
                            else
                                 if ((target-temp) > (target - temp2)) temp = temp2;

                            
                        }
                    }
                }
            }
            

            /*
            //
            while (k < nums.size()-1 ){
                if (k==0 ){
                    i=k+1; j=nums.size()-1;
                }
                else if (k == nums.size()-1){
                    i=0; j=k-1;
                }
                else{
                    i = 0; j = nums.size()-1;
                }
                if(k==0 ) temp = (nums[k]+nums[i]+nums[j]);
                    
                    
                    while (i<j){
                        while (i <j && nums[i] == nums[i+1])
                                i++;
                            
                        while (i<j && nums[j-1] ==  nums[j]) 
                                j--;
                        if (i == k && i < j) i++;
                        if (i < j && j == k) j--;

                        temp2 = (nums[k]+nums[i]+nums[j]);

                        if ((target -temp)>(target -temp2) )
                            //temp2 is better
                                j--;
                        else
                                i++;
                            
                        temp = temp2;
                            //what direction should we go to get closer?
                            //the way to make temp2 smaller is to make i larget
                         
                            
                    }
                
                k++;
            }  
            */      
              
        return temp ;
   
    }


};


int main(){
    //vector <int> a = {2,0,-1,1,5,-1};
   // vector <int> a = {-1,0,1,2,-1,-4};
  // vector <int> a = {-1, 0, 1};
    //vector <int> a = {0,0,0,0};
    //vector <int> a = {-2,0,1,1,2};
    //vector <int> a = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    vector <int> a = {1, 1,1,0};
    int target = -100;
    int ans;
    Solution sol;
    ans = sol.threeSumClosest(a, target);
    cout << "[ " ;
    for(auto z: a){
        cout << z << ", "; 
    }
        cout << " ] target: "<< target <<"= " << ans <<  endl;
    




    return 0;
}
//leet 560 Subarray Sum Equals K

//leet 560 Subarray

/*
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose 
sum equals to k.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


//from geeks for geeks
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        std::map <int, int> preMap(n,0);
        std::map <int, int> ::iterator it;
        int counter =0;
        int curr_sum=0;
        
        sort(nums.begin(), nums.end());
        //Populate Premap
        preMap[0] = nums[0];
        for (int i = 1; i<n ; ++i){
            preMap[i] = preMap[i-1] + nums[i]; 
        }


        // Pick a starting point
        for (int i = 0; i < n; i++) {
            curr_sum = nums[i];
            //if we are feeling lucky this will have a hit
            


            it = preMap.find(k-curr_sum - preMap[i+1]);
            if (it != preMap.end() || preMap[n-1] == (k-curr_sum)){
                //found  a value in teh prefixSum array that
                //totals the needed array sum.  So we know we can 
                //have a sub-array without going through all teh elements.

                counter++;
                continue;
            } 


            /*
            int preMax = max(preMap.begin()+i+1, preMap.end());
            if (preMax < k-curr_sum) {
                //there is no way for there to be a subarray
                continue;
            }

            
            
            
            // try all subarrays starting with 'i'
            for (int j = i + 1; j <= n; j++) {
                if (curr_sum == k) {
                    
                    counter++;
                }
                if (curr_sum > k || j == n)  //this does not work if any elements are neg
                    break;

                curr_sum = curr_sum + nums[j];
            }

            *//*
    
        }
        return counter;

    }
};


*/

//from leetcode site.
//i can't follow this
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cum=0; // cumulated sum
        map<int,int> rec; // prefix sum recorder
        int cnt = 0; // number of found subarray
        rec[0]++; // to take into account those subarrays that begin with index 0
        for(int i=0;i<nums.size();i++){
            cum += nums[i];
            cnt += rec[cum-k];
            rec[cum]++;
        }
        return cnt;
    }
};

void printIntVector(std::vector<int> v){
    std::cout << "[";
    for(int i = 0; i<v.size(); ++i){
        i==v.size()-1 ? std::cout << v[i] : std::cout << v[i] << ", ";
    }
    std::cout << "]";

}

int main(){
    Solution sol;
    vector<int> n = {1,-1,0};
    int k = 0;

    printIntVector(n);
    cout << endl;

    std::cout<< "Number of sub-arrays that equal: "<< k <<" is "<< sol.subarraySum(n,k) << endl;



    return 0;
}
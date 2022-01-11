//169  Majority Element
//leet169MajorityElement.cpp

//1/10/2022   leetcode


#include <iostream>
#include <map>
#include <vector>


using namespace std;


class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //majority element occurs more than n/2 times where n == nums.length

        map <int, int> result;
        
        
        int i = 0;
        int j = nums.size()-1;

         if (j ==0) return nums[0]; 
        
        while (i < j-1){
            result[nums[i]]+=1;
            result[nums[j]]+=1;
            i++;
            j--;
        }
        if ((nums.size()-1) %2 != (nums.size()-1)/2) result[nums[i]]+=1;
        
        int maxCount = 0;
        int maxValue = 0;
            for (std::map <int, int> ::iterator it = result.begin(); it!=result.end(); ++it){
                if(it->second > maxCount ){
                    maxCount = it->second;
                    maxValue =  it->first;
                }
            }
        


        return maxValue;
        
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
    vector <int> nums = {3,2,3};
    
    printIntVector(nums);

    std::cout << endl;
    cout<< "Majority Element: " <<sol.majorityElement(nums)<< endl;


    return 0;
}
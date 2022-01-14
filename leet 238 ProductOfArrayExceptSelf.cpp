// leet 238 Product of Array Except Self
//
//submitted and accepted.  43ms faster than 16% .  so not so fast

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        if (nums.size() <=1) return nums; 

        int length = nums.size();
        int p = length-1;
        vector<int> pre(length,0);
        vector<int> post(length,0);
        vector<int> prod(length,0);

        pre[0] = 1;
        post[p] = 1;
        //prod[0] = 1;
        //prod[1] = nums[0];
        for(int i = 1; i<length; ++i){
            --p;  //index the post position
            pre[i] = pre[i-1]*nums[i-1];
            post[p] = post[p+1]*nums[p+1];
           // prod[i+1] = prod[i]*nums[i];  //if it hits a zero every product after that will be 0
         }

        length--;
        while (p<=length){
            prod[p] = pre[p]*post[p];
            prod[length]= pre[length]*post[length];
            ++p;
            
        }

         return prod;
        
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
    vector<int> nums = {-1,1,0,3,-3};
    vector<int> result;
    Solution sol;
    result = sol.productExceptSelf(nums);


    
        printIntVector(nums);
        
    std::cout << endl;

     
        printIntVector(result);
       
    std::cout << endl;

    return 0;
}
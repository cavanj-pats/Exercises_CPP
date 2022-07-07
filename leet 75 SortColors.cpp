//


#include <iostream>
#include <vector>

using namespace std;

void refswap(int &x, int &y);
void printIntVector(std::vector<int> v);


class Solution {
public:
    void sortColors(vector<int>& nums) {
        //use a bubble sort algorithm

        bool swapped;
        int n = nums.size();
        for (int i = 0; i < n-1; i++)
        {
            swapped = false;
            for (int j = 0; j < n-i-1; j++)
            {
                if (nums[j] > nums[j+1])
                {
                    refswap(nums[j], nums[j+1]);
                    swapped = true;
                }
            }
        
            // IF no two elements were swapped by inner loop, then break
            if (swapped == false)
                break;
        }
    }
};

void refswap(int &x, int &y){
    //int temp=x;  the code looks cleaner when using references
    //but you really don't know you are working with references.
    x=x+y;
    y=x-y;
    x=x-y;
}

void printIntVector(std::vector<int> v){
    std::cout << "[";
    for(int i = 0; i<v.size(); ++i){
        i==v.size()-1 ? std::cout << v[i] : std::cout << v[i] << ", ";
    }
    std::cout << "]";

}



int main(){
    std::vector<int> nums = {2,0,2,1,1,0};
    Solution sol;

    printIntVector(nums);
    std::cout << endl;
    sol.sortColors(nums);
    printIntVector(nums);
    std::cout << endl;

    std::cout << endl;


    return 0;
}







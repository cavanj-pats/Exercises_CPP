//leet 48 Rotate Image  (rotate matrix 90 degrees clockwise)
//
//  1/11/2022

//submitted and accepted
//my initial mapping was incorrect but not that far off.


#include <iostream>
#include <vector>

using namespace std;


//using reference 
void refswap(int &x, int &y){
    //int temp=x;  the code looks cleaner when using references
    //but you really don't know you are working with references.
    x=x+y;
    y=x-y;
    x=x-y;
}


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int a = 0;
        int b = matrix[0].size()-1;

        while (a<b){
            for (int i=0; i<(b-a); i++){
                refswap(matrix[a][a+i], matrix[a+i][b]);
                refswap(matrix[a][a+i], matrix[b][b-i]);
                refswap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
        
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

    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;

    cout << "[";
    for(auto n:nums){
        printIntVector(n);
        n == nums[nums.size()-1] ? std::cout <<"]" : std::cout << ", ";
    }
    std::cout << endl;

    sol.rotate(nums);

    cout << "[";
    for(auto n:nums){
        printIntVector(n);
        n == nums[nums.size()-1] ? std::cout <<"]" : std::cout << ", ";
    }
    std::cout << endl;

    return 0;
}
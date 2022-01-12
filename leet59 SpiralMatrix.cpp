//leet 59 Spiral Matrix II
//1/12/2022

// submitted and accepted.  faster than 100%

#include <iostream>
#include <vector>

using namespace std;

/*
Fill the matrix n x n in a spiral manner
1. across top row.
2. down right most column
3. right to left across bottom row
4. up first column but do not over -write 0,0
5. go across 0+1 row
6. down n-1 column
7. across n-1 row  right to left
8. stop at 0+1 row
repeat
odd size matrix will end in center.
*/


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int colOffset = 0;
        int rowOffset = 0;
        int data = 0;
        vector<vector<int>> matrix(n,vector<int>(n,0));


        int a = 0;
        int b = n-1;
        while ( data < n*n){
            for (int i = a+colOffset; i<=b-colOffset; ++i){
                //fill row
                matrix[rowOffset][i] = ++data;   //FORMAT:  [row][column]
            }
            ++rowOffset;
            for (int i = a+rowOffset; i<= b-colOffset; ++i){
                //fill column
                matrix[i][b-colOffset] = ++data;
            }
           ++colOffset;
            for(int i = b-colOffset; i>=colOffset-1; --i){
                matrix[b-rowOffset+1][i] = ++data;
            }

            for(int i = b-rowOffset; i>a+rowOffset-1 ; --i){
                matrix[i][colOffset-1] = ++data;

            }
            
            
           
        }
        return matrix;

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

    vector<vector<int>> nums;  // = {{1,2,3},{4,5,6},{7,8,9}};
    Solution sol;

    
    nums = sol.generateMatrix(1);

    //cout << "[";
    for(auto n:nums){
        printIntVector(n);
        //n == nums[nums.size()-1] ? std::cout <<"]" : std::cout << ", ";
        std::cout << endl;
    }
    std::cout << endl;

    return 0;
}
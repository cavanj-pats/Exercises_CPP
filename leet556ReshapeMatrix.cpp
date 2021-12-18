//leet 556 Reshape the matrix


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();  //number of rows actually in the matrix
        int n = mat[0].size() ;  //number of columns

        vector<int> temp;
        vector<int> t;
        

        if (m * n != r * c) return mat;   //

        vector<vector<int>> ans(r,c,0);

        for (int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                temp.push_back(mat[i][j]);
            }
        }

        for (int i=0; i<temp.size(); ++i){

        }
        
    }
};


int main(){
    vector<int> nums1 = {2,0};
    vector<int> nums2 = {1};
    int n = 1;
    int m = 1;

    Solution sol;

    sol.merge(nums1, m, nums2, n);
    cout << "[";
    for(int n:nums1){
         cout << n ;
        if (n != nums1.back()) cout << ", ";
       
    }
    cout <<"]";

    return 0;

}
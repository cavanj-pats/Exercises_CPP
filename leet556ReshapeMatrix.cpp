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
        
        

        if (m * n != r * c) return mat;   //
        vector<int> t(c,0);
        vector<vector<int>> ans(r,t);//intialize to zeroess

        for (int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                temp.push_back(mat[i][j]);
            }
        }

        for (int i=0; i<temp.size(); ++i){
            ans[i/c][i%c]=temp[i];

        }
        
        return ans;
    }
};


int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    vector<vector<int>> mat;
    int r = 2;
    int c = 4;
    mat.push_back(nums1);
    mat.push_back(nums2);
    vector<vector<int>> ans;
    Solution sol;

    ans = sol.matrixReshape(mat,r,c);

   
    for(vector<int> t:ans){
         cout << "[";
        for(int n=0; n<t.size(); ++n){
            cout << t[n] ;
            if (n != t.size()-1) cout << ", ";
        
        }
    if(t == ans.back()) 
        cout <<"]";
    else
        cout << "],";
}

    return 0;

}
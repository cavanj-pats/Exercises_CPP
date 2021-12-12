//1314 Matrix block sum
//this is from a posting at leetcode.
//the poster describes the 2D prefix sum nicely.
//but the code si dificult to track.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    int sizeX, sizeY;
    int extractSum(int i, int j, const vector<vector<int> >& sum) {
        //this limits the code to only valid cells
        //when calculating the prefix sum,  there could be negative i or j.  
        //this hanldes that.
        //when retrieving the presum for the solution,  this handles invalid ranges of i and j that can occur when 
        // k is added or subtracted from the index.
        
        if (i < 0 || j < 0) return 0;
        if (i >= sizeX) i = sizeX - 1;
        if (j >= sizeY) j = sizeY - 1;
        return sum[i][j];
    }
        
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        sizeX = mat.size();   //this amounts to the number of columns.  X direction
        sizeY = mat[0].size();  //this amounts to the number of rows Y direction
        
        vector<vector<int>> sum(sizeX, vector<int>(sizeY, 0));  //this fills the Matrix with zeroes.

        // Calculate prefix matrix 
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                //from the defined math for prefix sum of Matrix
                //click on the link below and you can understand the below line of code.
                //essentially add up the element and all elements to the left and above the element
                //subtract out elements "double dipped"
                //https://tutorialspoint.dev/algorithm/dynamic-programming-algorithms/prefix-sum-2d-array
                sum[i][j] = mat[i][j] + extractSum(i-1, j, sum) + extractSum(i, j-1, sum) - extractSum(i-1, j-1, sum);
            }
        }
        
        // Use prefix matrix to calculate our sum
        vector<vector<int>> ans(sizeX, vector<int>(sizeY, 0));
        for (int i = 0; i < sizeX; i++) {
            for (int j = 0; j < sizeY; j++) {
                //the way to calculate the answer is given in the problem
                //sum is the presum vector
                //again this adds up and subtracts out "double dipped" data or data counted twice.
                ans[i][j] = extractSum(i+K, j+K, sum) - extractSum(i+K, j-K-1,sum) - extractSum (i-K-1, j+K, sum) + extractSum(i-K-1, j-K-1, sum);
            }
        }
        
        return ans;
    }
};


int main(){
    //string s = "**|**|***|";
    //string s = "***|**|*****|**||**|*";
    //

    vector<vector<int> > mat = {{1,2,3},{4,5,6},{7,8,9}};  
    //[[1,2,3],[4,5,6],[7,8,9]]
    int k = 1;
    Solution sol;
    
    vector <vector<int> > ans;
    ans = sol.matrixBlockSum(mat, k);

    for (auto a: ans){
        cout << "[";
        for(int i=0 ; i<a.size(); ++i){
            cout << a[i] ;
            if (i<a.size()-1) cout << ",";
        }
        cout << "]";
        if (a != ans.back()) cout << ",";
    }

    cout << endl;

    return 0;

}
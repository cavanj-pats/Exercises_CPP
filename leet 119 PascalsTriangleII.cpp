//leet 119 Pascal's Triangle
//
//   1/11/2022

//acceted by leetcode.  Ran faster than 100% and used less than 31% of memory compared to other submissions.


class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> pt = generate(rowIndex+1);

        return pt[rowIndex];
        
    }



    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int>> ans;
        
        for (int i=0; i<numRows; ++i){
            if (i==0) {
                temp.push_back(1);
                ans.push_back(temp);
                temp.clear();
                }
            if (i>0){
                temp.push_back(1);
                for(int j = 0; j<i-1 ; ++j){
                    temp.push_back(ans[i-1][j] + ans[i-1][j+1]);

                }
                temp.push_back(1);
                ans.push_back(temp);
                temp.clear();
            }
            

        }
        return ans;
    }
};
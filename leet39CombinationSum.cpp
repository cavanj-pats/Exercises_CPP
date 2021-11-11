//39. leet  Combination Sum

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int size=candidates.size();
        int t;
        int balance = target;
        vector<int> temp;
        vector<vector<int> ans;


        sort (candidates.begin(),candidates.end());

        for (int i = 0 ; i<size; ++i){
            t=candidates[i];
            if (t == 0) continue;
            while (balance > 0){
                temp.push_back(t);
                if (balance -t >= 0){
                    balance -=t;
                }
                if (balance = 0) ans.push_back(temp);
            }
//i think recursion will be better  like two loops and recursion or something 

            if (t == 1 ){
                for (int j=0; j<target; ++j) {temp.push_back(1);}
                ans.push_back(temp);
            }


        }
        
    }
};
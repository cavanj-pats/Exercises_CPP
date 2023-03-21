//leet 118 valid pascals triangle


//this code absolutely generates a pascal triangle perfectly.
//but numbers start to get very very large at n>=25


#include <iostream>
#include <vector>

using namespace std;






class Solution {
public:
    vector <vector<int> > generate(int numRows) {
        vector<int> temp;
        vector <vector <int> > ans;
        
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








int main(){
    vector<vector<int> > ans;
    Solution sol;
    ans = sol.generate(3);

    for(vector<int> t:ans){
         cout << "[";
        for(int n=0; n<t.size(); ++n){
            cout << t[n] ;
            if (n != t.size()-1) cout << ", ";
        
        }
    if(t == ans.back()) 
        cout <<  "]";
    else
        cout << "],";

    cout << endl; 

    }
    

    return 0;
    
    

}
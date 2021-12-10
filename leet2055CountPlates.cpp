//leet 2055 Count plates between candles

#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        //i've studied the idea of a prefix sum where a mapping is created
        //of the plate quantity at each index in string.
        int n = s.size();

        vector<int> ans;
        vector<int> prefixSumPlates(n,0);  //the sum of plates at a given index
        vector<int> prevCandle(n,-1);  //the index within s of the previous candle
        vector<int> nextCandle(n,n);  //the index within s of the next candle
        
        int first;
        int last;
        string temp;
       // int plateCount=0;
        //int candleCount=0;

        for(int i=0; i<n; ++i){
            prevCandle[i] = (s[i] == '*') ? ((i == 0) ? prevCandle[i] : prevCandle[i-1]) : i;

		    nextCandle[n-i-1] = (s[n-i-1] == '*') ? ((i == 0) ? nextCandle[n-i-1] : nextCandle[n-i]) : n-i-1;

		    prefixSumPlates[i] = (i == 0) ? (s[i] == '*') : prefixSumPlates[i-1] + (s[i] == '*');
        }

            
        for(auto q: queries){
            //first = s.find_first_of('|',q[0]);
            //last = s.find_last_of('|', q[1]);
            //plateCount = 0;
            first = nextCandle[q[0]] > q[1] ? 0 : nextCandle[q[0]];
            last = prevCandle[q[1]]< q[0] ? 0 : prevCandle[q[1]];
            
            //if(first >=q[0] && first < last && last <=q[1] ){
               //temp = s.substr(first,last-first);
               //sort(temp.begin(), temp.end());
               //plateCount = temp.find_first_of('|',0);
               
               
               ans.push_back(prefixSumPlates[last]- prefixSumPlates[first]);              

           // }  
           // else{
           //     ans.push_back(0);
            //}  
        

        }  

        
        return ans;  
    }
};


int main(){
    //string s = "**|**|***|";
    string s = "***|**|*****|**||**|*";

    vector<vector<int>> queries = {{1,17},{4,5},{14,17},{5,11},{15,16}};  //{{2,5},{5,9}};
    Solution sol;
    
    vector<int> pos;
    pos = sol.platesBetweenCandles(s, queries);

    for(int i=0 ; i<pos.size(); ++i){
        cout << pos[i] << ",";
    }

    cout << endl;

    return 0;

}


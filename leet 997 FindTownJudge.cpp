//leet 997 FindTheTownJudge

/*
Success
Details 
Runtime: 431 ms, faster than 6.57% of C++ online submissions for Find the Town Judge.
Memory Usage: 69 MB, less than 16.37% of C++ online submissions for Find the Town Judge.


//above is leet code discussion code. Mine did not work




class Solution{
    public:
int findJudge(int n, vector<vector<int>>& trust) {
        //this condition is to check if given input is empty but n==1
		
		if(trust.empty() && n==1)
            return 1;
		
		//counts outdegree of a person or node 
		//outdegree means number of nodes that are trusted by given specific node 
        
		vector<int> out(n+1,0);
		
		//counts indegree of a person or node 
		//indegree means number of nodes that trusts a given specific node
        
		vector<int> in(n+1,0);
		
		//loop counts indegree and outdegree
        
		for(auto edge : trust){
            out[edge[0]]++;
            in[edge[1]]++;
        }
		
		//if a node has outdegree==0 that means that node doesnot trust anyone and
		//indegree ==n-1 that means all other nodes trusts this node except himself
        
		for(int i=0;i<=n;i++){
            if(out[i]==0 && in[i]==n-1)
                return i;
        }
		//if there is no such node return -1
        return -1;
    }
};
*/


#include <unordered_map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




template <typename T1, typename T2>
struct lesser_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second < b.second;
    }
};


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> trustMap;
        unordered_map<int, int>::iterator it;
        int k = trust.size();
        
        //if (k <= n) return -1;  //everyone trusts someone
        for (int i = 1; i<=n; ++i){
            trustMap[i]=0;
        }
        for(int i = 0; i<k; ++i){
            trustMap[trust[i][0]] = trust[i][1];
        }
        /*
        for (auto t: trust){
            trustMap[t[0]] = t[1];
        }
         */
        
        
        vector<pair<int, int> > mapcopy(trustMap.begin(), trustMap.end());
        sort(mapcopy.begin(), mapcopy.end(), lesser_second<int, int>());
        
        //the first item in mapcopy should be teh answer
        if (mapcopy[0].second != 0 ) return -1;
        return mapcopy[0].first;
        
    }
};


int main(){
    Solution sol;
    vector<vector<int>> nums = {{1,3},{2,3}};
    int result = sol.findJudge(3, nums);

    //for(int i = 0; i<result.size(); ++i)
    //    cout <<  result[i] <<", ";


    cout << result << " " << endl;   

    return 0;
}
//leetLongestCommonPrefix

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp = "";
        string test=strs[0];
        bool allCommon = true;
        int smallestLength=strs[0].length();
        
       

        //the maximum common will be the size of the smallest string

        for(int i=1; i<strs.size(); i++){
            if (strs[i].length()<smallestLength){
                smallestLength = strs[i].length();
                test = strs[i]; //largest possible Common Previx
            }
        }

                
        for(int j=1; j<=test.size(); j++ ){
                
            for(int i=0; i<strs.size(); i++){
                if(strs[i].substr(0,j)!=test.substr(0,j)){
                        //if it gets here we know it is false
                        allCommon = false;
                
                }

            }
            if(allCommon){
                cp=test.substr(0,j);
            }
            else{
                if(j==1) cp="";
                if(j>1) cp=test.substr(0,j-1);
                return cp;
            }

        }


        return cp;
    }
};

int main(){ 
    Solution sol;
    vector <string> v = {"float", "flavor", "flake"};
    cout << "longest common prefix " << sol.longestCommonPrefix(v) << endl;


    return 0;

}
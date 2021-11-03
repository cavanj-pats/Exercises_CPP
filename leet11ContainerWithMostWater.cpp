//11.Container with the most water

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
            
            int idxStart=0;
            int idxEnd = height.size()-1;
            if(height.size()<=1) return 0;
            int temp= 0;

            while(idxStart < idxEnd){
                temp = max(temp, min(height[idxStart],height[idxEnd])*(idxEnd-idxStart));
                min(height[idxStart], height[idxEnd])==height[idxStart] ? idxStart++ : idxEnd-- ;
            }
                
            return temp;
    }
};



int main(){
    Solution sol;
    //vector<int> a = {2,3,4,5,18,17,6};
    vector<int> a = {1,8,6,2,5,4,8,3,7};
    int ans = sol.maxArea(a);

    std::cout << ans << std::endl;
    

    return 0;


}
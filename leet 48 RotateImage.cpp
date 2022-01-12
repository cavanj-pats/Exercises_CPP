//leet 48 Rotate Image  (rotate matrix 90 degrees clockwise)
//
//  1/11/2022


#include <iostream>
#include <vector>



//using reference 
void refswap(int &x, int &y){
    //int temp=x;  the code looks cleaner when using references
    //but you really don't know you are working with references.
    x=x+y;
    y=x-y;
    x=x-y;
}


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
    }
};
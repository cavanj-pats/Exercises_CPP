//leet 1184  shortest distance arount map

#include <iostream>
#include <vector>

using namespace std;




int helper(vector<int>& distance, int, int, int);

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int cw =0;
        int ccw=0;
        int n=distance.size();
        cw = helper(distance, start, destination, n);
        ccw = helper(distance, destination, start, n);
        if (cw < ccw) return cw;
        else return ccw;
    }
};


int helper(vector<int>& distance, int start, int destination, int n){
    
    if (start == destination) return 0;
    
    //go clockwise
    return  distance[start]+helper(distance, (start + 1)% n, destination, n);
    
   
    
    }



    int main(){
        Solution sol;
        vector<int> distance = {1,2,3,4};
        cout << sol.distanceBetweenBusStops(distance,0,3) << endl;

    }
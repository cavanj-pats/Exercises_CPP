//leet 461 hamming distance

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int hammingDistance(int x, int y) {
        //bool isDifferent = false;
        //vector<int> distance;
        int hd=0;

        for (int i=0; i<32; ++i){
            if (((x>>i) & 1) != ((y>>i) & 1)){
                //distance.push_back(i);
                hd++;
            }
            
            //if (distance.size()==2) return distance.back()-distance.front();
            
        }
        return hd; //distance.front();
    }
};

int main(){
    Solution sol;
    cout<< "Hamming 1,4= "<< sol.hammingDistance(1,4)<< endl;

    return 0;
}
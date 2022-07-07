//leet 1523 count of odd numbers in a range
//leet 1523 countOddInRange.cpp

//ran well

#include <istream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        
        if((high-low+1)%2 ==0){
            return (high-low+1)/2;
        }else{
            if (low % 2 == 0 ){
                return (high - low + 1)/2;
            } else {
                return (high - low + 1)/2 +1;
            }   
        }
        
        
    }
};
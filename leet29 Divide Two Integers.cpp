//leet29. Divide Two Ints - dont' use multiply divide or mod

//this works but exceeds the time limit.  which means i think that it is O(n) or greater
//leetcode looks for faster soluctions
//many people use the right or left shift operators  >>  or << which are bitwise operators
//i don't know how to use.

#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        long long numerator = (long long) dividend;
        long long denominator = (long long) divisor;
        
        long long counter=0;
        bool isNeg=false;
                
       // if( (long long) dividend == pow(-2,31) && divisor <0) return pow(2,31)-1;
        if (numerator ==0) return 0;
        if (denominator == 1) return (int) numerator;
        if (denominator == -1 && numerator == pow(-2,31)) return pow(2,31)-1;
        if (denominator == -1 ) return (int) -1 * numerator;
       
        if ( numerator < 0 ){
            numerator = -1*numerator ; //convert to positiv
            isNeg = !isNeg;
            
        }
        if(denominator < 0){
            denominator = -1 * denominator;
            isNeg = !isNeg;
        }

        for (int n = 31; n > -1; --n){
            //have to cast otherwise result will be zero if divisor << n exceeds 32 bits
            //since dividend is an int a large divisor<<n won't run through the 'if'
            if (( denominator<<n ) <= numerator){
                numerator = numerator - (denominator << n) ;
                counter += 1<<n;
                
                if (!isNeg && counter >= pow(2,31)-1) return pow(2,31)-1;
                if (isNeg && counter >= pow(2,31)) return pow(-2,31);
            }
        }

        if(isNeg) counter = counter *-1;
               
        return (int) counter;
    }
};


int main(){
    Solution sol;
    //std::cout << "2 << 31 " << ((long long) 2<<31) << endl;
   // std::cout << "7/-3 =" << sol.divide (7,-3) << endl;
    //std::cout << "-2147483648/2 =" << sol.divide(-2147483648,2) << endl;
    std::cout << "2147483647/2 =" << sol.divide(2147483647,2) << endl;
    return 0;
    
}
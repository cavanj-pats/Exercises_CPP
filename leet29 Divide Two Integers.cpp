//leet29. Divide Two Ints - dont' use multiply divide or mod

//this works but exceeds the time limit.  which means i think that it is O(n) or greater
//leetcode looks for faster soluctions
//many people use the right or left shift operators  >>  or << which are bitwise operators
//i don't know how to use.

#include <iostream>
#include <cmath>



class Solution {
public:
    int divide(int dividend, int divisor) {
      // int numerator;
       //int denominator;
        int ans;
        long long counter=0;
        bool isNeg=false;

        
       // if( (long long) dividend == pow(-2,31) && divisor <0) return pow(2,31)-1;
        if (dividend ==0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend == pow(-2,31)) return pow(2,31)-1;
        if (divisor == -1 ) return -1 * dividend;
       

        if (dividend < 0 ){
            if (divisor < 0){
                //result is positive
               //do nothing
            }
            else{
                //dividend =-1 * dividend;
                isNeg = true;
            }
        }
        else{
            if(divisor < 0){
                //divisor = -1 * divisor;
                isNeg = true;
            }
        }

        if (dividend < 0 && divisor < 0) {
              while (dividend <= divisor){
                  dividend -= divisor;
                  ++counter;
              }

               
        } else if(dividend > 0 && divisor >0) {
              while (dividend >= divisor){
                  dividend -= divisor;
                  ++counter;
              }
        } else if (dividend > 0 && divisor <0){
                while (dividend >= -1*(long long) divisor){
                  dividend += divisor;
                  ++counter;
              }

        } else        {
                while ( dividend <= -1*(long long) divisor){
                  dividend += divisor;
                  ++counter;
                }
           
                      
        }

        if(isNeg) counter = counter *-1;
        if (counter > pow(2,31)-1) return pow(2,31)-1;
        if (counter < pow(-2,31)) return pow(-2,31);
       
        return (int) counter;
    }
};


int main(){
    Solution sol;

    std::cout << "5/2 =" << sol.divide (5,2);
    return 0;
    
}
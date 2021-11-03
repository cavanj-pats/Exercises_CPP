//50.myPow   LeetCode


#include <iostream>


class Solution {
public:
    double myPow(double x, int n) {
        /* bool isNegExp = false;
        bool isEven = false;

        if(n%2 == 0 ) isEven = true;
        
        if(n==0) return 1;
        if(x == 0.0) return 0.0;
        if(x==1.0) return 1.0;
        if(x==-1 && !isEven ) return -1.0;
        if(x==-1 && isEven ) return 1.0;        
       
        if (x>1 && n==2147483647) return 21474833647;

         if(n == -2147483648) {
            if(x<0 && x<-1) return x*-1;
            //if(x>0 && x<1) return 1.000;
            if(x>1 || x<-1) return 1/2147483648;
         //   need a case if abs(x)<1  that will calculate but might take too long
        }
 */
        //if(n==2147483647) return x;


        
        /* if(x <=-100) x=-100.0;
        if(x >= 100 ) x=100.0;
               
        double ans = x; */
        
        /* if (n<0){
            isNegExp = true;
            if(n== -2147483648)
                n = 2147483647;
            else
                n=n*-1;
                
        } */
        if(n < 0){
			n++;
			return 1/x * myPow(1/x, -n);
		}
        else if (n >0)
        {
            if(n == 1) return x;
            if(n%2) return x*myPow(x*x, n/2);
            else return myPow(x*x, n/2);
        }
        else if (n == 0) return 1;
            return x;
        

        /* if (n % 2 == 0){
            for(int i=1; i<n/2; i++){
                    ans*=x*x;
            }
        }
        else 
        { 
            for(int i=2; i<n; i+=2){
                    ans*=x*x;
            }
            ans*=x;
        } */

       // if (ans>10000) ans=10000;

        /* if (!isNegExp) {
            return ans;
        }
        else
            return 1/ans; */
        
    }
};


int main (){
    Solution sol;
    std::cout << "-1, 2^31-1: "<< sol.myPow(-1, 2147483647) << std::endl;
   std::cout << "-1, -2^31: " << sol.myPow(-1, -2147483648) << std::endl;
    std::cout << "0.999999999, -2^31: " << sol.myPow(0.999999999, -2147483648) << std::endl;

    return 0;
}
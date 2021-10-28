// 7. Reverse Integer

#include <iostream>
#include <string>
#include <cmath>


using namespace std;

class Solution {
public:
    int reverse(long long int x) {
        string str = to_string(x);
        string ans="";
        int num=0;
        int i=0;
        int sign=0;
        
        
        
       
        if(x <= 1*pow(-2,31)) return 0;
        if(x>=pow(2,31)-1) return 0;
            
        if(str[0] == '-') {
            sign = -1;
            //ans= '-';
            //i++;
        }
        for(int j=str.length()-1; j>=0-sign; j--){
            ans+= str[j];
            i++;
        }
       if(ans.length()>10) return 0;  //as given in the proble>=
       if(ans.length()>=10 && (ans[0-sign]-48)>2) return 0;
       if(ans.length()>=10 && ans>"2147483647") return 0;
       if(sign ==-1 &&ans.length()>=10 && ans>"2147483648") return 0;
       
       for(int j=0; j<ans.length(); j++){
           num+=(ans[j]-48)*pow(10,ans.length()-1-j);
       }

        /*
        for(int j=str.length()-1; j>=0-sign; j--){
            if(j==str.length()-1 && str[j]-48 == 0){
                //ignore
                ans = "leading zero ignored";
            }
            else {
            num+=(str[j]-48) * pow(10,j+1+sign);
            //ans[i] = str[j];
            i++;
            }

        }
        */
        
        
        if(sign) return sign*num;
        return num;
    }
};


int main(){
    Solution sol;
   //long long  int num= -2147483649;
    //long long int num = 1534236469;
   // long long int num = 1563847412;
   long long int num = 123;
    cout << num << " reversed= "<< sol.reverse(num) << endl;

    return 0;

}
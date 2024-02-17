//leet 1281 sum and product of digits




#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int subtractProductAndSum(int n) {
       
        string strDigits = to_string(n);
        int prod = 1;
        int sum = 0;

        for(int i = 0; i<strDigits.size(); ++i) {
            int num = strDigits[i]-48;
            prod *= num;
            sum += num;

        }

        return prod - sum ;

        
    }
};


int main(){
    Solution sol;
    cout << sol.subtractProductAndSum(90) << endl;

    return 0;
}
//leet 1823 Find the Winner

#include <unordered_map>
#include <vector>
#include <iostream>


class Solution {
public:
    int findTheWinner(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res = (res + k) % i;
            
        return res + 1;
    
    }
};

int main(){
    Solution sol;
    std::cout << "5,2 =: " <<sol.findTheWinner(5,2) << std::endl;



    return 0;
}
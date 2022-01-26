//

#include <unordered_map>
#include <vector>
#include <iostream>


class Solution {
public:
    int findTheWinner(int n, int k) {
        int i = n;
        int j = 0;
        int pos=0;
        std::vector <int> player;

        for (int j=0; j<n; ++j) player.push_back(j+1);

        //use modular or clock arithmetic to remove players


        do{
            j += k;
            pos = (j < i ? j : j%i)-1;
            std::cout << player[pos] << ", ";
            player.erase(player.begin()+pos);
            --i;
            j++;
            
        }while (i>1);
        std::cout << std::endl;

        return player[0];
    }
};

int main(){
    Solution sol;
    std::cout << "5,2 =: " <<sol.findTheWinner(5,2) << std::endl;



    return 0;
}
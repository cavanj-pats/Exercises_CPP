//leet 121 best time to buy or sell stock
//leet121StockMarketTiming.cpp
//Dec 18, 2021
#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=prices[0];
        int maxReturn = 0;

        for(int i=1 ; i<prices.size(); ++i){
            if (prices[i]<minPrice)
                minPrice = prices[i];
                
                if(prices[i]-minPrice > maxReturn)
                    maxReturn = prices[i]-minPrice;

        }

        return maxReturn;
    }
};


int main(){
    vector<int> prices = {7,6,4,3,12};
    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}
#include<vector>
#include<limits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = numeric_limits<int>::max();
        for (auto price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > profit){
                profit = price - minPrice;
            }
        }
        return profit;
    }
};
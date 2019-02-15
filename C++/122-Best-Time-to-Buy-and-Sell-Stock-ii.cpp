#include<vector>
#include<limits>
using namespace std;

// 遍历一边，把所有正的差值加起来
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
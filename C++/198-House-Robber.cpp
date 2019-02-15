#include<vector>
#include<algorithm>
using namespace std;

// 不太明白是为什么
class Solution {
public:
    int rob(vector<int>& nums) {
        int last = 0, result = 0;
        for (const auto& i : nums) {
            auto tmp = result;
            result = max(last + i, result);
            last = tmp;
        }
        return result;
    }
};
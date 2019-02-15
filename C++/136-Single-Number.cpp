#include<vector>
using namespace std;

// 直接用异或操作，因为vector中只有一个数出现一次，其他数都出现两次
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) {
            res ^= num;
        }
        return res;
    }
};

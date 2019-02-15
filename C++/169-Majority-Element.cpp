#include<vector>
using namespace std;

// 摩尔投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        auto res = nums[0];
        int count = 1;
        for (auto num : nums) {
            if (num != res) {
                --count;
                if (count == 0) {
                    count = 1;
                    res = num;
                }
            } else {
                ++count;
            }
        }
        return res;
    }
};
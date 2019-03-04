#include<vector>
using namespace std;

// 用一个sum记录当前子序列和，如果sum==0了就重新置零继续遍历
// 每次遍历更新最大的子序列和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], sum = 0;
        for (const auto& n : nums) {
            if (sum > 0) {
                sum += n;
            } else {
                sum = n;
            }
            res = sum > res ? sum : res;
        }
        return res;
    }
};
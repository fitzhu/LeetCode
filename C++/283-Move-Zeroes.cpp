#include<vector>
using namespace std;

// 两个指针遍历，交换0值和非零值得位置
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0; // 指针1：遇到非零值往前移动
        for (auto& num : nums) {
            if (num) {
                swap(nums[pos++], num);
            }
        }
    }
};
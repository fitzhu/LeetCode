#include<vector>
using namespace std;

// 从后往前遍历，用一个标志step记录当前位置到末尾的距离。如果遇到的元素可以到达最后一行，则截断后边的元素。否则继续往前
// 若最后剩下的元素大于1个，则可以判断为假。否则就是真
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= step) {
                step = 1;
            } else {
                ++step;
            }
        }
        return step <= 1;
    }
};
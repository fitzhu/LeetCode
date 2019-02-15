#include<vector>

using namespace std;

// 二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};

int main() {
    vector<int> nums({1,3,5,6});
    int target = 0;
    Solution tmp;
    auto ret = tmp.searchInsert(nums, target);
}
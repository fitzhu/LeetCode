#include<vector>
#include<algorithm>
using namespace std;

/*
    1.将数组排序（升序排列）
    2.定义三个指针，i，j，k。遍历i，那么这个问题就可以转化为在i之后的数组的两数问题
    3.使用双指针j，k：j从前往后, k从后往前
        三数和sum大于target时，应该减小sum，即指针k往前移动
        三数和sum小于target时，应该增大sum，即指针j往后移动
        注意跳过重复的数
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        const int target = 0;

        // sort nums, increasing order
        sort(nums.begin(), nums.end());
        for (int i = 0; static_cast<int>(nums.size()) - 2; ++i) { // 这里需要写显式强制类型转换，不然size_t类型会负值溢出
            if (i == 0 || nums[i] != nums[i - 1]) { // skip duplicated
                for (int j = i + 1, k = nums.size() - 1; j < k; ) { // 双指针j、k, j从前往后, k从后往前
                    if (j - 1 > i && nums[j] == nums[j - 1]) { // skip duplicated
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) { // skip duplicated
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) { // should decrease sum
                            --k;
                        } else if (sum < target) { // should increase sum
                            ++j;
                        } else {
                            ans.push_back({nums[i], nums[j], nums[k]});
                            ++j, --k;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums({});
    Solution tmp;
    auto res = tmp.threeSum(nums);
}
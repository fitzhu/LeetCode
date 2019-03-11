#include<vector>
#include<algorithm>
using namespace std;

/*
    思路参考15-3Sum, 四数之和就再嵌套一层for
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        // sort nums, increasing order
        sort(nums.begin(), nums.end());
        for (int i = 0; i < static_cast<int>(nums.size()) - 3; ++i) {
            if (i && nums[i] == nums[i - 1]) { // skip duplicated
                continue;
            }
            for (int j = i + 1; j < static_cast<int>(nums.size()) - 2; ++j) {
                if (j != i + 1 && nums[j] == nums[j - 1]) { // skip duplicated
                    continue;
                }
                int sum = target - nums[i] - nums[j];
                int left = j + 1, right = static_cast<int>(nums.size()) - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left, --right;
                        while (left < right && nums[left - 1] == nums[left]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right + 1]) {
                            --right;
                        }
                    } else {
                        if (nums[left] + nums[right] > sum) {
                            --right;
                        } else {
                            ++left;
                        }
                    } 
                }
            }
        }
        return ans;
    }
};
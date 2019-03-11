#include<vector>
#include<algorithm>
#include<limits>
using namespace std;

/*
    思路参考15-3Sum, 不同之处在于: 需要一个min_diff变量维护所有sum与target的最小diff, 以更新ans
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 0, min_diff = numeric_limits<int>::max();

        // sort nums, increasing order
        sort(nums.begin(), nums.end());
        for (int i = 0; i < static_cast<int>(nums.size()) - 2; ++i) {
            for (int j = i + 1, k = nums.size() - 1; j < k; ) {
                const auto sum = nums[i] + nums[j] + nums[k];
                if (sum > target) { // should decrease sum
                    --k;
                } else if (sum < target) { // should increase sum
                    ++j;
                } else {
                    return target;
                }

                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
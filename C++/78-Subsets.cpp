#include<vector>
using namespace std;

// dfs+动态规划问题，从前往后遍历，从每个当前位置到最后每个位置进一步遍历，当前数加入到临时vector
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums, 0, subset, res);
        return res;
    }
private:
    void helper(const vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& res) {
        if (index > nums.size()) {
            return;
        }
        res.emplace_back(subset);
        for (size_t i = index; i < nums.size(); ++i) {
            subset.emplace_back(nums[i]);
            helper(nums, i + 1, subset, res);
            subset.pop_back(); // 回溯
        }
        return;
    }
};

#include<vector>
using namespace std;

// 全排列就是从第一个数字起每个数分别与它后面的数字交换，明白这个意思之后，就可以用递归的思路写了
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
private:
    void helper(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if (begin == nums.size() - 1) {
            res.emplace_back(nums);
        }
        for (size_t i = begin; i < nums.size(); ++i) {
            swap(nums[begin], nums[i]);
            helper(nums, begin + 1, res);
            swap(nums[begin], nums[i]); // 把顺序交换回来进行回溯
        }
        return;
    }
};
#include<vector>
#include<algrithm>
using namespace std;

// 先排序，从前往后遍历，从当前位置往后每一个位置均调用递归函数，当与目标数的差值小于0时return
// 动态规划的思想
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(candidates, target, 0, v, res);
        return res;
    }
private:
    void helper(const vector<int>& candidates, int diff, int begin, vector<int>& v, vector<vector<int>>& res) {
        if (diff == 0) {
            res.emplace_back(v);
            return;
        }
        // 因为i是从begin开始取的，所以它包含了重复使用当前数的情况
        for (size_t i = begin; i < candidates.size(); ++i) {
            if (diff < 0) {
                return;
            }
            v.emplace_back(candidates[i]);
            helper(candidates, diff - candidates[i], i, v, res);
            v.pop_back();
        }
    }
};

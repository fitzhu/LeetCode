#include<vector>
#include<algrithm>
using namespace std;

// 先排序，从前往后遍历，从当前位置往后每一个位置均调用递归函数，当与目标数的差值小于0时return
// 动态规划的思想
// 与40-Combination-Sum一样，只是需要跳过重复的元素
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> v;
        helper(candidates, target, 0, v, res);
        return res;
    }
private:
    void helper(const vector<int>& candidates, int diff, int begin, vector<int>& v, vector<vector<int>>& res) {
        if (diff == 0) {
            res.push_back(v);
            return;
        }

        for (size_t i = begin; i < candidates.size(); ++i) {
            if (diff < candidates[i]) {
                return;
            }
            if( i > begin && candidates[i] == candidates[i - 1]) { // skip duplicates
                continue;
            }
            v.push_back(candidates[i]);
            helper(candidates, diff - candidates[i], i + 1, v, res);
            v.pop_back();
        }
    }
};
#include<vector>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归解法
class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> out;
        vector<vector<int>> res;
        helper(root, sum, out, res);
        return res;
    }
private:
    void helper(TreeNode* node, int sum, vector<int>& out, vector<vector<int>>& res) {
        if (node == nullptr) {
            return;
        }
        out.emplace_back(node->val);
        if (sum == node->val && !node->left && !node->right) {
            res.emplace_back(out);
        }
        helper(node->left, sum - node->val, out, res);
        helper(node->right, sum - node->val, out, res);
        out.pop_back();
    }
};

// 非递归解法，类似二叉树遍历，用stack来回溯路径
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<TreeNode*> s;
        vector<vector<int>> res;
        TreeNode *cur = root, *pre = nullptr;
        int val = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.emplace_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = s.back();
            if (!cur->left && !cur->right && val == sum) {
                vector<int> v;
                for (auto it : s) {
                    v.push_back(it->val);
                }
                res.push_back(v);
            }
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            } else {
                pre = cur;
                val -= cur->val;
                s.pop_back();
                cur = nullptr;
            }
        }
        return res;
    }
};
#include<vector>
#include<stack>
#include<pair>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉树遍历，无论是中序、先序还是后序，访问node的顺序都是一样的，只是什么时候输出的问题
// 非递归的写法，用stack存储之前访问的过的node（因为访问完左节点后，还有访问右节点，需要能够回溯）
// 这里用stack<pair<node*, bool>>来存储，使用标志位控制是否输出
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, bool>> treeNodeStack;
        treeNodeStack.emplace(root, false);
        while (!treeNodeStack.empty()) {
            bool visited;
            tie(root, visited) = treeNodeStack.top();
            treeNodeStack.pop();
            if (root == nullptr) {
                continue;
            }
            if (visited) {
                res.emplace_back(root->val);
            } else {
                // 因为栈是先入后出的，所以会把root->right先入栈
                // 中序遍历的话，pair<node*, true>放中间，输出node->val
                treeNodeStack.emplace(root->right, false);
                treeNodeStack.emplace(root, true);
                treeNodeStack.emplace(root->left, false);
            }
        }
        return res;
    }
};

// 递归解法
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* root, vector<int>& tmp) {
        if (root != nullptr) {
            helper(root->left, tmp);
            tmp.emplace_back(root->val);
            helper(root->right, tmp);
        }
    }
};
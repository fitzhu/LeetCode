#include<vector>
#include<queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 在某一层级遍历node时，用队列存储下一层级的node
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode* > que;

        if (root != nullptr) {
            que.emplace(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* front = que.front();
                que.pop();
                level.emplace_back(front->val);
                if (front->left != nullptr){
                    que.emplace(front->left);
                }
                if (front->right != nullptr) {
                    que.emplace(front->right);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};
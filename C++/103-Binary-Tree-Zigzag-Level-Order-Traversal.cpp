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

// 和层次遍历一样，在某一层级遍历node时，用队列存储下一层级的node。只是需要一个标志位判断是否需要将输出reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode* > que;
        int flag = 0;

        if (root != nullptr) {
            que.emplace(root);
        }

        while (!que.empty()) {
            vector<int> level;
            int size = que.size();
            flag += 1;

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
            if (flag % 2 == 0) reverse(level.begin(), level.end());
            res.emplace_back(level);
        }
        return res;
    }
};
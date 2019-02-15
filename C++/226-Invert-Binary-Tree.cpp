
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};
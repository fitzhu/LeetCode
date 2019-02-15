#include<algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 因为是二叉搜索树，只需要找到第一个在这两个数值区间的数就行了
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto s = min(p->val, q->val);
        auto b = max(p->val, q->val);

        while (root->val < s || root->val > b) {
            root = s <= root->val ? root->left : root->right;
        }
        return root;
    }
};
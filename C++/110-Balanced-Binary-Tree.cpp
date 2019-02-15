#include<iostream>
#include<algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        if (abs(countFloor(root->left) - countFloor(root->right)) > 1) {
            return false;
        }

        if (isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        } else {
            return false;
        }
    }
private:
    int countFloor(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(countFloor(root->left), countFloor(root->right));
    }
};
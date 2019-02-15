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

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<TreeNode*> nodes;

        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> tmp;
            for (size_t i = 0; i < size; ++i) {
                TreeNode* p = nodes.front();
                nodes.pop();
                tmp.push_back(p->val);
                if(p->left)
                    nodes.push(p->left);
                if(p->right)
                    nodes.push(p->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

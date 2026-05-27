/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> res;
        preOrder(res, root);
        cout << res.size() << endl;
        return res[k - 1]->val;
    }

    void preOrder(vector<TreeNode*>& res, TreeNode* root) {
        if (!root) {
            return;
        }
        preOrder(res, root->left);
        res.push_back(root);
        preOrder(res, root->right);
    }
};

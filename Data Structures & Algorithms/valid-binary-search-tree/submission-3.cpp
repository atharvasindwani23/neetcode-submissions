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
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i + 1] <= res[i]) {
                return false;
            }
        }
        return true;
    }

    void preorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        preorder(root->left, res);
        res.push_back(root->val);
        preorder(root->right, res);
    }
};

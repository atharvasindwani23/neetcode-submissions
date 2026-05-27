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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        int diff = depth(root->left) - depth(root->right);
        diff = abs(diff);
        if (diff > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int depth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
};

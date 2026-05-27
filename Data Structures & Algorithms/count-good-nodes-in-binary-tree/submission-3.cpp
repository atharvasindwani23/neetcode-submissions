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
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int curr = root->val;
        int count = 0;
        helper(root, curr, count);
        return count;
    }

    void helper(TreeNode* root, int curr, int& count) {
        if (!root) {
            return;
        }
        
        if (root->val >= curr) {
            count++;
        }

        helper(root->left, max(curr, root->val), count);
        helper(root->right, max(curr, root->val), count);
    }
};
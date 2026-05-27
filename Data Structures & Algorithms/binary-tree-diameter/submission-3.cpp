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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameterHelper(root, dia);
        return dia - 1;
    }

    int diameterHelper(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }
        int lh = diameterHelper(root->left, diameter);
        int rh = diameterHelper(root->right, diameter);

        diameter = max(lh + rh + 1, diameter);
        return max(1 + diameterHelper(root->left, diameter), 1 + diameterHelper(root->right, diameter));
    }
    
};

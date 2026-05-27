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
    TreeNode* invertTree(TreeNode* root) {
        //switch root->left and root->right at every level

        if (!root) {
            return nullptr;
        }
        if (!root->left && !root->right) {
            return root;
        }
        if (root->left && root->right) {
            TreeNode* swapper = root->left;
            root->left = root->right;
            root->right = swapper;
            invertTree(root->left);
            invertTree(root->right);
        } else if (root->left) {
            root->right = root->left;
            root->left = nullptr;
            invertTree(root->right);
        } else if (root->right) {
            root->left = root->right;
            root->right = nullptr;
            invertTree(root->left);
        }
            return root;
        }
    };

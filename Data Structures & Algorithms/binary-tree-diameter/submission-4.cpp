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
        vector<TreeNode*> vec;
        preOrder(root, vec);
        int diameter = 0;
        for (int i = 0; i < vec.size(); i++) {
            TreeNode* curr = vec[i];
            diameter = max(diameter, height(curr->left) + height(curr->right));
        }
        return diameter;
    }

    void preOrder(TreeNode* root, vector<TreeNode*>& vec) {
        if (!root) {
            return;
        }
        vec.push_back(root);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(1 + height(root->left), 1 + height(root->right));
    }
};

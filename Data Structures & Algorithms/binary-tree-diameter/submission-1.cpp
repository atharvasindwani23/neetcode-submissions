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
        preorder(vec, root);
        int dia = 0;
        if (vec.size() == 0) {
            cout << "meow" << endl;
        }
        for (TreeNode* curr : vec) {
            dia = max(dia, height(curr->left) + height(curr->right));
        }
        return dia;
    }

    void preorder(vector<TreeNode*>& vec, TreeNode* root) {
        if (!root) {
            return;
        }
        vec.push_back(root);
        preorder(vec, root->left);
        preorder(vec, root->right);
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(1 + height(root->left), 1 + height(root->right));
    }
};

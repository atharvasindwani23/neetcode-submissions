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
        vector<int> elements;
        inOrderTraversal(root, elements);
        for (int i = 0; i < elements.size() - 1; i++) {
            if (elements[i] >= elements[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inOrderTraversal(TreeNode* root, vector<int>& elements) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left, elements);
        elements.push_back(root->val);
        inOrderTraversal(root->right, elements);
    }
};

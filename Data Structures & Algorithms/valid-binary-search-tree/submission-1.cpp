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
        vector<int> ordered;
        inOrderTraversal(root, ordered);
        for (unsigned int i = 0; i < ordered.size() - 1; i++) {
            if (ordered[i] >= ordered[i + 1]) {
                return false;
            }
        }
        return true;
    }

    void inOrderTraversal(TreeNode* root, vector<int>& inOrder) {
        if (!root) {
            return;
        }
        inOrderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inOrderTraversal(root->right, inOrder);

    }
};

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
        vector<int> nodes;
        inOrder(root, nodes);
        for (int i = 0; i < nodes.size() - 1; i++) {
            if (nodes[i] >= nodes[i + 1]) {
                return false;
            }
        }
        return true;
    }
    void inOrder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        inOrder(root->left, nodes);
        nodes.push_back(root->val);
        inOrder(root->right, nodes);
    }
};

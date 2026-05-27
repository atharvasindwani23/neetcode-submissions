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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrd;
        inOrder(root, inOrd);
        return inOrd[k - 1];
    }

    void inOrder(TreeNode* root, vector<int>& travy) {
        if (!root) {
            return;
        }
        inOrder(root->left, travy);
        travy.push_back(root->val);
        inOrder(root->right, travy);
    }
};

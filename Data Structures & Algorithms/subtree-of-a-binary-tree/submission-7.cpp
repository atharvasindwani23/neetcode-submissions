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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root && subRoot) {
            return false;
        }
        if (!root && !subRoot) {
            return true;
        }
        if (root && !subRoot) {
            return false;
        }
        if (root->val == subRoot->val && isSameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && q) {
            return false;
        }
        if (!q && p) {
            return false;
        }
        if (!q && !p) {
            return true;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val;
    }

};

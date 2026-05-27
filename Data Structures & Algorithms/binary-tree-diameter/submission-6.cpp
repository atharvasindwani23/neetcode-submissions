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
        if (!root) {
            return 0;
        }
        return max(max(height(root->left) + height(root->right), diameterOfBinaryTree(root->left)), diameterOfBinaryTree(root->right));
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }


    //logic for diameter is to find the longest path;
    //how can we go ahead and do that?
    //how is this different from maxdepth?
    //logic is to look at the maxdepth of any point on the left, and to the right and add them
    //and to do this for every treenode 
};

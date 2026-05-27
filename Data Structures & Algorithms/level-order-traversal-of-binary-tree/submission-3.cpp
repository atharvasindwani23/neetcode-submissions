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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> res;
     if (!root) {
        return {};
     }
     levelOrderTraversal(root, res);
     return res;   
    }
    void levelOrderTraversal(TreeNode* root, vector<vector<int>>& levels) {
        queue<TreeNode*> elements;
        elements.push(root);

        while (!elements.empty()) {

            int levelSize = elements.size();
            vector<int> level;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = elements.front();
                elements.pop();
                level.push_back(curr->val);

                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
            levels.push_back(level);
        }
    }

};

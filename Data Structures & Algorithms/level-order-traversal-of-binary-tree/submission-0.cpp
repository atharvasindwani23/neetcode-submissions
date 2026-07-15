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
        vector<vector<int>> levels;

        if (!root) {
            return {};
        }

        queue<TreeNode*> elements;
        elements.push(root);

        while (!elements.empty()) {
            int len = elements.size();
            vector<int> level;
            for (int i = 0; i < len; i++) {
            TreeNode* curr = elements.front();
            level.push_back(curr->val);
            elements.pop(); 

            if (curr->left) {
                elements.push(curr->left);
            }
            if (curr->right) {
                elements.push(curr->right);
            }
        }
        levels.push_back(level);
    }
    return levels;
    }
};

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
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> elements;
        if (!root) {
            return {};
        }
        elements.push(root);

        while (!elements.empty()) {
            int length = elements.size();
            vector<int> level;
            for (int i = 0; i < length; i++) {
                auto node = elements.front();
                elements.pop();
                level.push_back(node->val);

                if (node->left) {
                    elements.push(node->left);
                }
                if (node->right) {
                    elements.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};

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
        vector<vector<int>> result;
        if (!root) {
            return result;
        }
        vector<int> flag;
        queue<TreeNode*> elements;
        elements.push(root);
        while (!elements.empty()) {
            int len = elements.size();

            for (int i = 0; i < len; i++) {
                TreeNode* curr = elements.front();
                elements.pop();
                flag.push_back(curr->val);
                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
            result.push_back(flag);
            flag.clear();
        }
        return result;
    }
};

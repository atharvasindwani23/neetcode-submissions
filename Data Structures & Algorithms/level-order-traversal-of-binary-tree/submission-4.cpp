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
        if (!root) {
            return {};
        }

        vector<vector<int>> result;

        queue<TreeNode*> levels;
        levels.push(root);
        while (!levels.empty()) {

            int len = levels.size();
            vector<int> flag;
            for (int i = 0; i < len; i++) {
                TreeNode* curr = levels.front();
                levels.pop();
                flag.push_back(curr->val);

                if (curr->left) {
                    levels.push(curr->left);
                }
                if (curr->right) {
                    levels.push(curr->right);
                }
            }
            result.push_back(flag);
        }
        return result;
    }
};

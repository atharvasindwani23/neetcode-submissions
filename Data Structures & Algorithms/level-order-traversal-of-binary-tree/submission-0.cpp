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
       std::queue<TreeNode*> q;
       if (!root) {
        return {};
       }
       q.push(root);
       vector<vector<int>> returner;
       vector<int> level;
       level.push_back(root->val);
       while (!q.empty()) {
        int c = level.size();
        returner.push_back(level);
        level.clear();
        for (int i = 0; i < c; i++) {
        TreeNode* curr = q.front();
        if (curr->left) {
            q.push(curr->left);
            level.push_back(curr->left->val);
        } if (curr->right) {
            q.push(curr->right);
            level.push_back(curr->right->val);
        }
        q.pop();
       }
       }
    return returner;
     } 
    };

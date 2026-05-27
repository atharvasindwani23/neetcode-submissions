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
       
       res.push_back({root->val});
       queue<TreeNode*> q;
       q.push(root);
       while (!q.empty()) {

        int q_size = q.size();

        vector<int> flag;
        
        for (int i = 0; i < q_size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr->left) {
                q.push(curr->left);
                flag.push_back(curr->left->val);
            }
            if (curr->right) {
                q.push(curr->right);
                flag.push_back(curr->right->val);
            }
        }
        if (flag.empty()) {
          break;  
        }
        res.push_back(flag);
        flag.clear();
       }
       return res;
    }
};

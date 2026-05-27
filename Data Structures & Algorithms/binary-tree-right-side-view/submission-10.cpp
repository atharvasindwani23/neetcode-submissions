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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
       if (!root) {
            return result;
        }
        queue<TreeNode*> elements;
        elements.push(root);
        while (!elements.empty()) {
            int len = elements.size();

            for (int i = 0; i < len; i++) {
                if (i == len - 1) {
                    result.push_back(elements.front()->val);
                }
                TreeNode* curr = elements.front();
                elements.pop();
                if (curr->left) {
                    elements.push(curr->left);
                }
                if (curr->right) {
                    elements.push(curr->right);
                }
            }
        }
        return result;
    } 
};

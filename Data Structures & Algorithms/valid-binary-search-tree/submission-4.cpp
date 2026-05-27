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
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> res;
        cout << "chakka hai kya bkl" << endl;
        preOrder(res, root);
        cout << res.size() << endl;
        for (int i = 1; i < res.size(); i++) {
            if (res[i]->val <= res[i - 1]->val) {
                return false;
            }
        }
        return true;
    }
    void preOrder(vector<TreeNode*>& res, TreeNode* root) {
        if (!root) {
            return;
        }
        preOrder(res, root->left);
        res.push_back(root);
        preOrder(res, root->right);
    }
};

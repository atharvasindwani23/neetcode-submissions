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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> parent;
        constructor(parent, root);
        parent[root] = nullptr;
        vector<TreeNode*> val_p;
        vector<TreeNode*> val_q;
        while (p) {
            val_p.push_back(p);
            p = parent[p];
        }
        while (q) {
            val_q.push_back(q);
            q = parent[q];
        }
        for (int i  = 0; i < val_p.size(); i++) {
            for (int j = 0; j < val_q.size(); j++) {
                if (val_p[i]->val == val_q[j]->val) {
                    return val_p[i];
                }
            }
        }
    }

    //a helper function which makes some sort of a parent map while recursively finding a particular node p
    void constructor(map<TreeNode*, TreeNode*>&parent, TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->left) {
            parent[root->left] = root;
        }
        if (root->right) {
            parent[root->right] = root;
        }
        constructor(parent, root->left);
        constructor(parent, root->right);
    }

};

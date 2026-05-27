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
        std::map<TreeNode*, TreeNode*> parentMap;
        helper(root, parentMap);
        parentMap[root] = nullptr;
        vector<TreeNode*> p_array = filler(p, parentMap);
        std::cout << "P" << std::endl;
        for (TreeNode* node : p_array) {
            std::cout << node->val << std::endl;
        }
        vector<TreeNode*> q_array = filler(q, parentMap);
        std::cout << "Q" << std::endl;
        for (TreeNode* node : q_array) {
            std::cout << node->val << std::endl;
        }
        TreeNode* value = nullptr;
        for (int i = 0; i < p_array.size() ; i++) {
            for (int j = 0; j < q_array.size(); j++) {
            if (p_array[i]->val == q_array[j]->val) {
                  return p_array[i];
            }
        }
        }
        return root;
    }
    void helper(TreeNode* root, std::map<TreeNode*, TreeNode*>& parentMap) {
        if (!root) {
            return;
        }
        if (root->left) {
            parentMap[root->left] = root;
        }
        if (root->right) {
            parentMap[root->right] = root;
        }
        helper(root->left, parentMap);
        helper(root->right, parentMap);
    }
    vector<TreeNode*> filler(TreeNode* curr, std::map<TreeNode*, TreeNode*>&parentMap) {
        vector<TreeNode*> returner;
        while (curr) {
            returner.push_back(curr);
            curr = parentMap[curr];
        }
        return returner;
    }
};

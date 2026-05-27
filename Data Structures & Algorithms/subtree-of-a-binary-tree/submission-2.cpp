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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //keep going down until you ran into a scenario where root of main tree matches subroot, then algo for sametree
        //let helper function one return the ref where both vals match
        vector<TreeNode*> res;
        match(root, subRoot, res);
        for (TreeNode* node : res) {
          if(sameTree(node, subRoot)) {
            return true;
          }
          }
          return false;
        }
    void match(TreeNode* root, TreeNode* subRoot, vector<TreeNode*>& matches) {
        if (!root) {
            return;
        }
        if (root->val == subRoot->val) {
            matches.push_back(root);
        }
            match(root->left, subRoot, matches);
            match(root->right, subRoot, matches);
        }

    bool sameTree(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        if (!root1) {
            return false;
        } 
        if (!root2) {
            return false;
        }
        return (sameTree(root1->left, root2->left) && sameTree(root1->right, root2->right) && root1->val == root2->val);
    }

    };

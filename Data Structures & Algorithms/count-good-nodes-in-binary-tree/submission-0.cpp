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
    int goodNodes(TreeNode* root) {
        int c = 1;
        dfs(root, c, root->val);
        return c;
    }

    void dfs(TreeNode* root, int& c, int value) {
        if (!root) {
            cout << "myow?" << endl;
            return;
        }
        if (!root->left && !root->right) {
            if (root->val > value) {
                c++;
            }
            return;
        }
        if (root->left) {
            cout << root->left->val;
            if (root->left->val >= value) {
                c++;
            }
            dfs(root->left, c, max(root->left->val, value));
        }
        if (root->right) {
            if (root->right->val >= value) {
                c++;
            }
            dfs(root->right, c, max(root->right->val,value));
        }
    }


    //stack only makes more sense actually, you have the root initially, then if you see an element > then the root you add it to the stack, if you see an element < the root, you dont add it to the stack, whenever you add something to the stack do ++, and pop elements one by one once you found something greater.
    //now we know stack and dfs are closely releated so talking reccursively heres what im thinking
    //dfs(root) = dfs(root->left) + 1, if root->left->val > root->val
};

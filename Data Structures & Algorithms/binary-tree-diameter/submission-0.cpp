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
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = height(root->left) + height(root->right);
        cout << height(root) << endl;
        maxDiameter(root, dia);
        return dia;   
    }

    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return max(1 + height(root->left), 1 + height(root->right));
    }
    int diameter(TreeNode* root) {
        return height(root->left) + height(root->right);
    }
    void maxDiameter(TreeNode* root, int &dia) {
        if (!root) {
            return;
        }
        if (root->left) {
            dia = max(dia, diameter(root->left));
            maxDiameter(root->left, dia);
        }
        if (root->right) {
            dia = max(dia, diameter(root->right));
            maxDiameter(root->right, dia);            
        }
    }

    //longest path bw any two nodes in the tree
    //length of the path, since it doesnt have to pass through the root of the tree you arent obliged to just do height(tree->left) + height(tree->right) + 1;
    //here the thing you need to remember is that you dont have to necessarily be bounded to the root, your root can be anything
};

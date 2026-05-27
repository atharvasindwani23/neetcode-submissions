class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;                 // number of edges on the longest path
        height(root, diameter);
        return diameter;
    }

private:
    // Returns height (in nodes) of the subtree; updates diameter (in edges)
    int height(TreeNode* node, int& diameter) {
        if (!node) return 0;
        int lh = height(node->left,  diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh + rh); // edges through this node
        return 1 + max(lh, rh); // height in nodes


        //THIS IS SO SMART CONVERTS AN O(N^2) INTO A NEAT O(N)
    }
};

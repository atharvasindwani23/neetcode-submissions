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
    
    vector<vector<int>> res;
    vector<int> rightView;
    levelOrderTraversal(res, root);
    for (vector<int> vec : res) {
        rightView.push_back(vec[vec.size() - 1]);
    }
        return rightView;
    }
    
   void levelOrderTraversal(vector<vector<int>>& res, TreeNode* root) {
    if (!root) return; 

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int c = q.size();
        std::vector<int> currentLevelValues; // Holds values of Level N nodes

        for (int i = 0; i < c; i++) {
            TreeNode* curr = q.front();
            q.pop();

            // 1. Record the value of the node being processed (Level N)
            currentLevelValues.push_back(curr->val); 

            // 2. Prepare the queue for the *next* level (Level N+1)
            if (curr->left) {
                q.push(curr->left);
            }
            if (curr->right) {
                q.push(curr->right);
            }
        }
        res.push_back(currentLevelValues);
    }
}




};

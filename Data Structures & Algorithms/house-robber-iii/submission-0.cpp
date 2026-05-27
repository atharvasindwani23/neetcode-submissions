class Solution {
public:
    int rob(TreeNode* root) {
        // dp[{node, canRob}] -> max amount
        map<pair<TreeNode*, int>, int> dp;
        return helper(root, 1, dp); // start with canRob = 1
    }
private:
    int helper(TreeNode* node, int canRob, map<pair<TreeNode*, int>, int>& dp) {
        if (!node) return 0;
        auto key = make_pair(node, canRob);
        if (dp.count(key)) return dp[key];

        // Option 1: skip this node (children can be robbed)
        int skip = helper(node->left, 1, dp) + helper(node->right, 1, dp);

        int best = skip;
        if (canRob) {
            // Option 2: rob this node (children cannot be robbed)
            int take = node->val + helper(node->left, 0, dp) + helper(node->right, 0, dp);
            best = max(best, take);
        }
        return dp[key] = best;
    }
};

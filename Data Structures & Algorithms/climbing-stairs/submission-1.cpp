class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp (n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
    }

    //think about this by breaking the puzzle down n pieces, to reach stair n all u need to do is reach stair n - 1 or stair n - 2
    //thats our whole dp logic.
};

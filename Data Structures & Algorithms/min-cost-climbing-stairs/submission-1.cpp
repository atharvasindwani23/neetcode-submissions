class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        int size = cost.size();
        dp[size - 1] = cost[size - 1];
        dp[size - 2] = cost[size - 2];
        for (int i  = size - 3; i >= 0; i--) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        return min(dp[0], dp[1]);
    }
    //if you pay then you can go either to the i + 1th or i + 2nd floor
    //can start at idx 0 or idx 1,
    //[i...n] approach sounds easier and more trivial
};

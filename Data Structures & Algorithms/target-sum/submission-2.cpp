class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);

        //dp[i] represents that i have taken the first "i" elements
        //dp[i][j] represents the number of ways to make j having taken the first i elements

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (auto &p : dp[i]) {
                //im going through taking in 0 -> n elements, and i then also fill out the
                dp[i + 1][p.first + nums[i]] += p.second;
                dp[i + 1][p.first - nums[i]] += p.second;
            }
        }
        return dp[n][target];
    }
};
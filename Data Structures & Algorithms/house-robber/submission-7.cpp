class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);

        dp[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    //if rob, you cannot rob the next house

    //dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
};

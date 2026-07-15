class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int n = nums.size();
        dp[n - 1] = nums[nums.size() - 1];
        dp[n - 2] = max(nums[nums.size() - 2], nums[nums.size() - 1]);

        for (int i  = n - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    //basically logiic is if i decide to rob house i, i cant then rob the house behind me or ahead of me
    //so at any posiitoon i i have two choices, i either a) pick up the value and jump to a spot two ahead
    //so something like if im at i, ill go to i + 2;
    //or i decide to not pick up anything and just go one step ahead
    //the better of those two choices is what ill do
    //so dp[i] = nums[i] + dp[i + 2] || dp[i + 1]
    //and again answer here would be dp[0] 
};

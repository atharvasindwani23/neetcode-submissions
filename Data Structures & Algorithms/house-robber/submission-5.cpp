class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(size,0);
        if (nums.size() == 1) {
            return nums[0];
        }
        dp[size - 1] = nums[size - 1];
        dp[size - 2] = max(nums[size - 2], nums[size - 1]);
        for (int i  = size - 3; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }

    //if you rob at house i you cannot rob house at (i + 1);
    //two choices rob at i and go to i + 2 or dont rob and go to i + 1
    //i...n approach again more natural
};

class Solution {
public:
    int rob(vector<int>& nums) {
        //max houseRobber[1...5], houseRobber[0..4]
        //ez
        vector<int> copy  = nums;
        if (nums.size() == 1) {
            return nums[0];
        }
        copy.erase(copy.begin());
        nums.pop_back();
        return max(houseRobber(nums), houseRobber(copy));
    }
    int houseRobber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int len = nums.size();
        vector<int>dp(len,0);
        dp[len - 1] = nums[len  - 1];
        dp[len - 2] = max(nums[len - 1], nums[len - 2]);
        for (int i  = len - 3; i >= 0; i--) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};

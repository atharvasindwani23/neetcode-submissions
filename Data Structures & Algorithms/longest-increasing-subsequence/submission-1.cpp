class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int LIS = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (dp.back() < nums[i]) { 
                dp.push_back(nums[i]);
                LIS++;
                continue;
            }

            int idx = lower_bound(dp.begin(), 
                                  dp.end(), nums[i]) - dp.begin();
            dp[idx] = nums[i]; 
        }

        return LIS;
    }
};
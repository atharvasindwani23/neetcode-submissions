class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums[0] > 0) {
            return res;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < 0) {
                    l++;
                } else if (sum > 0) {
                    r--;
                } else {
                    res.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while (nums[l] == nums[l-1]) {
                        l++;
                    } 
                }
            }
        }
        return res;
    }
};

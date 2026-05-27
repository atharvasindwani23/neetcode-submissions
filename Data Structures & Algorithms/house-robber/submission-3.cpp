class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>robber(nums.size(), 0);
        if (nums.size() == 1) {
            return nums[0];
        }
        robber[n - 1] = nums[n - 1];
        robber[n - 2] = max(nums[n - 1], nums[n - 2]);
        if (nums.size() == 2) {
            return robber[0];
        }
        for (int i = n - 3; i >= 0; i--) {
            std::cout << i;
            robber[i] = max(nums[i] + robber[i + 2], robber[i + 1]);
        }
        return robber[0];
    }

    //if you rob at i you cannot rob at i + 1
    //so two options -> nums[i] + rob(i + 2) OR rob(i + 1) [skip curr house]
    //base cases -> i = n -> ROB
    //base case -> i = n - 1 -> rob whatevers greater
};

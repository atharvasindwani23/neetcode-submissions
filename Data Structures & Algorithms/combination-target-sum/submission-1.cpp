class Solution {
public:
    vector<vector<int>> returner;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(target, 0,curr, nums);
        return returner;
    }
    void backtrack(int target, int i, vector<int>& curr, vector<int>& nums) {
        if (target == 0) {
            returner.push_back(curr);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
        curr.push_back(nums[i]);
        backtrack(target - nums[i], i, curr, nums);
        curr.pop_back();
        backtrack(target, i + 1, curr, nums);
    }
};

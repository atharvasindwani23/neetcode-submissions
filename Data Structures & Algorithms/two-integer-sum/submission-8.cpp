class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> checker;
        for (int i = 0; i < nums.size(); i++) {
            int difference = target - nums[i];
            if (checker.count(difference)) {
                return {checker[difference], i};
            }
            checker[nums[i]] = i;
        }
        return {};
    }
};

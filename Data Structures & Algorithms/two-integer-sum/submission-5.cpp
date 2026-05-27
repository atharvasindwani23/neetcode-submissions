class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,vector<int>> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            numToIndex[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numToIndex.count(complement)) {
                if (numToIndex[complement].size() == 1 && complement != nums[i]) {
                
                return {i, numToIndex[complement][0]};
            } else {
                if (numToIndex[complement].size() == 2) {
                return {numToIndex[complement][0], numToIndex[complement][1]};
                }
            }
        }
        }
        return {0, 1};
    }

};

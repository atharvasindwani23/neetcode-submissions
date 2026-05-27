class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numToIndex;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numToIndex.count(complement)) {
                vec.push_back(i);
                vec.push_back(numToIndex[complement]);
                sort(vec.begin(), vec.end());
                return vec;
            }
            numToIndex[nums[i]] = i;
        }
        return {};
    }
};

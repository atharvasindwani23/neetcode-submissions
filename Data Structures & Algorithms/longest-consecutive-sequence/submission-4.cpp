class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> present;
        for (int num : nums) {
            present[num] = true;
        }
        vector<int> startIndexes;
        for (int i = 0; i < nums.size(); i++) {
            if (present[nums[i] - 1] == false) {
                startIndexes.push_back(i);
            }
        }
        int maxLen = 0;

        for (int idx : startIndexes) {
            int temp = nums[idx];
            int count = 0;
            while (present[temp]) {
                count++;
                temp++;
                maxLen = max(maxLen, count);
            }
        }
        return maxLen;
    }

    //1 -> identify starting components 
};

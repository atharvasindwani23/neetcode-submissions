class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::map<int,bool>present;
        for (int num : nums) {
            present[num] = true;
        }
        for (int i = 0; i <= nums.size(); i++) {
            if (!present[i]) {
                return i;
            }
        }
        return -1;
    }
};

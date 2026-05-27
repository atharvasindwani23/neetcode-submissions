class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int rot = k % nums.size();
        vector<int>res(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (i + rot <= nums.size() - 1) {
            res[i + rot] = nums[i];
            } else {
                res[i + rot - nums.size()] = nums[i];
            }
        }
        nums = res;
    }

    //k is how many steps you need to rotate it by
    // remember to use the mod operation, as rotations get same per mod
    // [1 2 3 4 5 6 7 8] -> rotate by rot basically means every index gets increased by 4,
    //if adding it by 4 makes it eceed smth, then subtract it, idx + 4 - 8
};
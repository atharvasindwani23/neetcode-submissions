class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                idx.push_back(i);
            }
        }
        int c = 0;
        for (int i : idx) {
            nums.erase(nums.begin() + i - c);
            c++;
        }
        return nums.size();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
           for (int i = 0; i <= nums.size() - k; i++) {
            res.push_back(maxReturn(i, nums, k));
           }
           return res;
    }

    int maxReturn(int idx, vector<int>& nums, int k) {
        int res = INT_MIN;
        for (int i =  idx; i < idx + k; i++) {
            res = max(res, nums[i]);
        }
        return res;
    }
};

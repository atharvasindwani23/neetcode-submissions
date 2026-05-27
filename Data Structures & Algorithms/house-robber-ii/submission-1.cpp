class Solution {
public:
    int rob(vector<int>& nums) {
       vector<int> copy = nums;
       if (nums.size() == 1) {
        return nums[0];
       }
       nums.erase(nums.begin());
       copy.pop_back();
       return max(helper(nums), helper(copy));
    }
    int helper(vector<int> nums) {
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


    //create two different dp's, [0, n - 2], [1, n - 1], will this work? lets think.

};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixProduct(nums.size(), 1);
        prefixProduct[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i];
        }
        vector<int> suffixProduct(nums.size(), 1);
        suffixProduct[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i];
        }
        vector<int> result(nums.size(), 1);
        for (int i = 1; i < result.size() - 1; i++) {
            result[i] = prefixProduct[i - 1] * suffixProduct[i + 1];
        }
        result[0] = suffixProduct[1];
        result[result.size() - 1] = prefixProduct[result.size() - 2];
        return result;
    }

    
};

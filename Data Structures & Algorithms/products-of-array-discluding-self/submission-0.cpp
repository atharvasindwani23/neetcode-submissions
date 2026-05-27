class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       std::vector<int> prefix_array(nums.size(), 1);
       std::vector<int> suffix_array(nums.size(), 1);
       for (int i = 1; i < nums.size(); i++) {
            prefix_array[i] = prefix_array[i - 1] * nums[i - 1];
       }
       for (int i = nums.size() - 2; i >= 0; i--) {
            suffix_array[i] = suffix_array[i + 1] * nums[i + 1];
       }
       std::vector<int> returner(nums.size());

       for (int i = 0; i < nums.size(); i++) {
        std::cout << prefix_array[i] << std::endl;
        std::cout << suffix_array[i] << std::endl;
        returner[i] = prefix_array[i] * suffix_array[i];
       }
       return returner;
    }
};
//ok think 0(n) operation how can we do it, without using the division operator
// we can do left * right but that in itself will make it an O(n^2) operation we want to do it in one sweep
// can we use maps or smth?


/// [1 2 4 6]
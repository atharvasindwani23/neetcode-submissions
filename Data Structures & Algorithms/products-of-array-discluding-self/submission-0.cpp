class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> rightProduct(nums.size());
        vector<int> leftProduct(nums.size());

        rightProduct[nums.size() - 1] = nums[nums.size() - 1];
        leftProduct[0] = nums[0];
        for (int i = nums.size() - 1; i > 0; i--) {
            rightProduct[i - 1] = nums[i - 1] * rightProduct[i];
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            leftProduct[i + 1] =  leftProduct[i] * nums[i + 1];
        }

        vector<int> result(nums.size());
        result[0] = rightProduct[1];
        result[nums.size() - 1] = leftProduct[nums.size() - 2];

        for (int i = 1; i <= nums.size() - 2; i++) {
            result[i] = rightProduct[i + 1] * leftProduct[i - 1];
        }
        return result;
    }

    //two arrays one which multiplies everything to the right
    //the other which multiplies everything to the left
    //then just combine the two
    //call the arrays rightProduct; leftProduct;
    //rightProduct[i] * leftProduct[i] is what we need for each i essentially; thats the whole logic.
};

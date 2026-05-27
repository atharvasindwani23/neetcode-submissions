class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int first = 0;
        int last = 0;
        int maxim = INT_MIN;
        if (nums.size() == 1) {
            return nums[0];
        }
        while (last < nums.size()) {
            int sum = 0;
            for (int i = first; i <= last; i++) {
                sum += nums[i];
            }
            std::cout << sum << std::endl;
            maxim = std::max(sum, maxim);
            if (sum < 0) {
                first = last + 1;
            }
            last++;
        }
        return maxim;
    }

    //conventional sliding window question
    //q to ask yourself -> where are my initial pointers supposed to be, whats the ending condn, //whats the moving condn
    //last part is trickiest to figure out
};

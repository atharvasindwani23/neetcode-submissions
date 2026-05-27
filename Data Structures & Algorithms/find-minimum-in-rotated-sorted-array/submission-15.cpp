class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        std::cout << maxIdx(nums) << std::endl;
        int maxId = maxIdx(nums);
        if (maxId == nums.size() - 1) {
            return nums[0];
        }
        return nums[maxId + 1];
    }
    int maxIdx(vector<int> &nums) {
        if (nums[0] < nums[nums.size() - 1]) {
            return nums.size() - 1;
        }
        int lower = 0;
        int upper = nums.size() - 1;
        while (lower <= upper) {
            std::cout << lower << std::endl;
            std::cout << upper << std::endl;
            int mid = (lower + upper) / 2;
            if (mid == 0) {
                if (nums[0] > nums[1]) {
                    return 0;
                } else {
                    return 1;
                }
            }
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[lower] <= nums[mid]) {
                lower = mid + 1;
            } else {
                upper = mid - 1;
            }
        }
        return -1;
    }

    //the min element will always be one ahead of the max element, so find the max idx then j return the min idx ez
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int counter = 0;
        while (left <= right) {
            counter++;
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (counter > nums.size()) {
                std::cout << "ola" << std::endl;
                return -1;
            }
        }
        std::cout << "nigger" << std::endl;
       return -1;
    }
};

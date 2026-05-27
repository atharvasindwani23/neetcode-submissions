class Solution {
public:
    int search(vector<int>& nums, int target) {
     int idx = pivotFinder(nums) + 1;
     std::cout << idx << std::endl;
     std::vector<int> firstHalf(nums.begin(), nums.begin() + idx);
     std::vector<int> secondHalf(nums.begin() + idx, nums.end());
     int first = binarySearch(firstHalf, target);
     int second = binarySearch(secondHalf, target);
     if (first == -1 && second != -1) {
        std::cout << "hello" << std::endl;
        return second + idx;
     } else {
        std::cout << "over" << std::endl;
        return first;
     }
     return -1;
    }

    int pivotFinder(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        if (nums[left] < nums[right]) {
            return right;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == 0) {
                if (nums[mid] > nums[mid + 1]) {
                    std::cout << "here" << std::endl;
                    return mid;
                }
            }
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (nums[left] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        std::cout << "nigger" << std::endl;
        return -1;
    }
    
    int binarySearch(vector<int> lookFor, int target) {
        int left = 0;
        int right = lookFor.size() - 1;
        int count = 0;
        while (left <= right) {
            count++;
            int mid = (left + right) / 2;
            if (lookFor[mid] == target) {
                return mid;
            }
            if (lookFor[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (count > lookFor.size()) {
                return -1;
            }
        }
        return -1;
    }


    //find max element then do two binary searches so 3 O(n) operations
};

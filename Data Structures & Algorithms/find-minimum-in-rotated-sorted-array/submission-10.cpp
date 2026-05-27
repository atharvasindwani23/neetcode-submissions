class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums[left] < nums[right]) {
            return nums[left];
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid == 0) {
                if (nums[1] > nums[0]) {
                    return nums[2];
                } else {
                    return nums[1];
                }
            }
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                std::cout << mid + 1 << std::endl;
                return nums[mid + 1];
            }
            if (nums[left] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    //basically its two sorted arrays conjoined together, thats the whole question
    //think trivially at first
    //remember binary search is about breaking things down
    // a hint also is to notice the largest element is just before it
    //cant really do anything with j that tho lol
    //min element will be the one jiske dono doosre side pe things will be greater
    // ie arr[x] > arr[y] && arr[y] < arr[z]

    //doing it by conculuding that min element will be one ahead of max element
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lower = 0;
        int upper = numbers.size() - 1;
        while (lower < upper) {
            if (numbers[lower] + numbers[upper] == target) {
                return {lower + 1, upper + 1};
            } else if (numbers[lower] + numbers[upper] > target) {
                upper--;
            } else {
                lower++;
            }
        }
        return {};
    }


    //two pointers at extreme ends
    //add them up, if two low shift right ptr to the middle, else shift left ptr to the middle
};

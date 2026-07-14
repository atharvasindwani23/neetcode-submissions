class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
        }

        vector<int> starts;

        for (int num : nums) {
            if (!numbers.count(num - 1)) {
                starts.push_back(num);
            }
        }
        if (nums.size() == 0) {
            return 0;
        }
        int len = 1;

        for (int start : starts) {
            int x = start;
            int count = 1;
            while (numbers.count(x + 1)) {
            x++;
            count++;
        }
        len = max(len, count);
    }
        return len;
    }
    //create a list of starts, then keep going forward so overall time complexity is o(n)
};

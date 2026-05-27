class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> present;
        int res = 0;
        for (int num : nums) {
            present[num] = true;
        }
        vector<int> startingValues;
        for (auto x = present.begin(); x != present.end(); x++) {
            if (present[x->first - 1] == false) {
                startingValues.push_back(x->first);
            }
        }
        for (int start : startingValues) {
            int flag = start;
            int count = 0;
            while (present[flag]) {
                flag++;
                count++;
            }
            res = max(res, count);
            count = 0;
        }
        return res;
    }
};

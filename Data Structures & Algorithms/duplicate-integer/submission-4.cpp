class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto x = freq.begin(); x != freq.end(); x++) {
            if (x->second > 1) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::map<int,int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto x = freq.begin(); x != freq.end(); x++) {
            if (x->second != 1) {
                return true;
            }
        }
        return false;
    }
};
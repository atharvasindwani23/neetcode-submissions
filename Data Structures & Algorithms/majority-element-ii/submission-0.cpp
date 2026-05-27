class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int greater = nums.size() / 3 + 1;
        vector<int> res;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            if (x->second >= greater) {
                res.push_back(x->first);
            }
        }
        return res;
    }
};
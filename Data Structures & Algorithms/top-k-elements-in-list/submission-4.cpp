class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> res;
        map<int, vector<int>> freqToNum;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto x = freq.begin(); x != freq.end(); x++) {
            freqToNum[x->second].push_back(x->first);
        }
        for (int i = nums.size(); i >= 1; i--) {
            if (freqToNum.count(i)) {
                for (int num : freqToNum[i]) {
                    res.push_back(num);
                    if (res.size() == k) {
                        return res;
                    }
                }
            }
        }
        return {};
    }
};

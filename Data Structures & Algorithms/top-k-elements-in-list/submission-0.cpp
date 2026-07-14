class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        unordered_map<int, vector<int>> frequencyToNums_;
        for (int num : nums) {
            frequency[num]++;
        }
        for (auto x = frequency.begin(); x != frequency.end(); x++) {
            frequencyToNums_[x->second].push_back(x->first);
        }
        vector<int> key;
        for (int i = nums.size(); i >= 0; i--) {
            if (frequencyToNums_.count(i)) {
                for (int ele : frequencyToNums_[i]) {
                    key.push_back(ele);
                    if (key.size() == k) {
                        return key;
                    }
                }
            }
        }
        return key;
    }
};

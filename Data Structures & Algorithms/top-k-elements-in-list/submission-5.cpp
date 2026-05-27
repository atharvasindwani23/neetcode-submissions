class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> freqMap;
        unordered_map<int, int> frequency;

        for (int num : nums) {
            frequency[num]++;
        }
        for (auto x = frequency.begin(); x != frequency.end(); x++) {
            freqMap[x->second].push_back(x->first);
        }
        
        vector<int> result;

        for (int i = nums.size(); i >= 0; i--) {
            for (int num : freqMap[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
        return {};
    }
};

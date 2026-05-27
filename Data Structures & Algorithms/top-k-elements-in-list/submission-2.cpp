class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int, int> freq;
     map<int, vector<int>> flag;
     for (int num : nums) {
        freq[num]++;
     }
     for (auto x = freq.begin(); x!= freq.end(); x++) {
        flag[x->second].push_back(x->first);
     }
     vector<int> res;
     for (int i = nums.size(); i >= 0; i--) {
        for (int num : flag[i]) {
            res.push_back(num);
            if (res.size() == k) {
                return res;
            }
        }
     }
     return {};
    }

    //can do by maps and prioirty queues ill implement both.
};

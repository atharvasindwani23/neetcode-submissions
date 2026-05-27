class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     map<int, int> freq;
     priority_queue<pair<int,int>>pq;
     for (int num : nums) {
        freq[num]++;
     }
     for (auto x = freq.begin(); x!= freq.end(); x++) {
        pq.push({x->second, x->first});
     }
     vector<int> res;
     while (pq.size() != 0) {
        auto x = pq.top();
        pq.pop();
        res.push_back(x.second);
        if (res.size() == k) {
            return res;
        }
     }
     return {};
    }

    //can do by maps and prioirty queues ill implement both.
};

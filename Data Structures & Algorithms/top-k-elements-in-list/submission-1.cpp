class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<int> returner;
        std::map<int,int> freq;
        std::map<int, vector<int>> rev_freq;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto x = freq.begin(); x != freq.end(); x++) {
            rev_freq[x->second].push_back(x->first);
        }
        std::cout << rev_freq[3].size() << std::endl;
        std::cout << rev_freq[2].size() << std::endl;
        std::cout << rev_freq[1].size() << std::endl;

        for (int i = nums.size(); i >= 0; i--) {
            if (rev_freq.count(i)) {
                for (int num : rev_freq[i]) {
                    returner.push_back(num);
                    if (returner.size() == k) {
                        return returner;
                    }
                }
            }
        }
        std::cout << "print" << std::endl;
        return {};
    }
};

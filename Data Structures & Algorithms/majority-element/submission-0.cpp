class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        int maxi = 0;
        int returner = 0;
        for (auto x = freq.begin(); x != freq.end(); x++) {
            if (maxi < x->second) {
                returner = x->first;
                maxi = x->second;
            }
        }
        return returner;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
        int l = 0, r = 0, res = 0;
        int maxFreq = 0;

        while (r < s.size()) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            int winSize = r - l + 1;
            if (winSize - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> frequency;

        int res = 0;
        int l = 0;
        int maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            frequency[s[r]]++;
            maxf = max(maxf, frequency[s[r]]);

            while ((r - l + 1) - maxf > k) {
                frequency[s[l]]--;
                l++;
            }
            res = max(r - l + 1, res);
        }
        return res;
    }
};

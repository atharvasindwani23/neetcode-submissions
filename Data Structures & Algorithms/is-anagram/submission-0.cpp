class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::map<char, int> freq_s;
        std::map<char, int> freq_t;
        for (char ch : s) {
            freq_s[ch]++;
        }
        for (char ch : t) {
            freq_t[ch]++;
        }
        for (char ch : s) {
            if (freq_t[ch] != freq_s[ch]) {
                return false;
            }
        }
        return true;
    }
};

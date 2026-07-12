class Solution {
public:
    bool isAnagram(string s, string t) {
        //sort strings and check if they're the same.
        //use a map and check if the frequency of the characters is the same in each of the cases
        unordered_map<char,int> freq_s;
        unordered_map<char, int> freq_t;

        for (char ch : s) {
            freq_s[ch]++;
        }
        for (char ch : t) {
            freq_t[ch]++;
        }
        if (freq_s.size() != freq_t.size()) {
            return false;
        }
        for (auto x = freq_s.begin(); x != freq_s.end(); x++) {
            if (x->second != freq_t[x->first]) {
                return false;
            }
        }
        return true;
    }
};

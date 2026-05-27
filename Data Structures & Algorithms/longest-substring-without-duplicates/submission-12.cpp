class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> letterToIndex;
        int l = 0;
        int r = 0;
        if (s.size() == 0) {
            return 0;
        }
        int winSize = 1;
        while (r < s.size()) {
            char ch = s[r];
            if (letterToIndex.count(ch)) {
                l = max(letterToIndex[ch] + 1, l);
            }
            letterToIndex[ch] = r;
            winSize = max(winSize, r - l + 1);
            r++;
        }
        return winSize;
    }
    //a b c d e a
    //0 1 2 3 4 5

    // we can do this extremely optimally by storing a map of all times of char to index
};

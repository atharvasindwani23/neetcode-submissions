class Solution {
public:
    string longestPalindrome(string s) {
        string returner = "";
        int maxSize = 0;
        for (int i = 0; i < s.size(); i++) {
            string odd = OddPalin(s, i);
            string even = EvenPalin(s, i);
            string longer = (odd.size() > even.size()) ? odd : even;
            if (longer.size() > maxSize) {
                maxSize = longer.size();
                returner = longer;
            }
        }
        return returner;
    }

    string OddPalin(string s, int idx) {
        int left = idx, right = idx;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string EvenPalin(string s, int idx) {
        int left = idx, right = idx + 1;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};

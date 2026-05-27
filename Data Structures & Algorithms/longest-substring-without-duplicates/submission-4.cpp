class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::map<char,bool> checker;
        int returner = 0;
        int length = 0;
        int start = 0;
        int end = 0;
        while (end < s.size()) {
            if (!checker[s[end]]) {
                std::cout << "enter";
                checker[s[end]] = true;
                length++;
                end++;
            } else {
                checker.clear();
                if (length > returner) {
                    returner = length;
                }
                length = 0;
                start++;
                end = start;
            } 
        }
        if (length > returner) {
            return length;
        }
        return returner;
    }
};

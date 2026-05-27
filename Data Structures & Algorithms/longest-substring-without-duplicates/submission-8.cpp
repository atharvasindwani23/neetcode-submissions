class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lower = 0;
        int upper = 1;
        set<char> unique;
        if (s.size() == 0) {
            return 0;
        }
        int res = 1;
        unique.insert(s[0]);
        while (upper < s.size()) {
            if (unique.count(s[upper]) != 0) {
                res = max(res, upper - lower);
                lower++;
                unique.clear();
                std::cout << s[lower] << std::endl;
                unique.insert(s[lower]);
                upper = lower + 1;
            } else {
               std::cout << s[upper] << std::endl;
               unique.insert(s[upper]); 
               upper++; 
            }
        }
        return max(res, upper - lower);
    }
    //sliding window technique obv
};

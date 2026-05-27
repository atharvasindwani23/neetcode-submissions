class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        if (s.size() == 1) {
            return s;
        }
        for (int i = 0; i < s.size() - 1; i++) {
            if (oddPalin(s,i).size() >evenPalin(s,i).size()) {
                if (res.size() < oddPalin(s,i).size()) {
                    res = oddPalin(s,i);
                }
            } else {
                if (res.size() < evenPalin(s,i).size()) {
                    res = evenPalin(s,i);
                }
            }
        }
        return res;
    }


    string oddPalin(string s, int i) {
        int lower = i;
        int upper = i;
        while (s[lower] == s[upper] && lower >= 0 && upper <= s.size() - 1) {
            lower--;
            upper++;
        }
        return s.substr(lower + 1,upper - lower - 1);
    }
    string evenPalin(string s, int i) {
        int lower = i;
        int upper = i + 1;
        std::cout << lower << std::endl;
        std::cout << upper << std::endl;
        while(s[lower] == s[upper] && lower >= 0 && upper <= s.size() - 1) {
            lower--;
            upper++;
        }
        std::cout << lower << std::endl;
        std::cout << upper << std::endl;
        return s.substr(lower + 1,upper - lower - 1);
    }

    //pick each to be the centre and extend out
    //obviously here the "trick" to remember is that you need to consider odd and even pallindromes
    //have two diff helper functions for that
};

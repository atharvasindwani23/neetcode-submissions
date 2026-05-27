class Solution {
public:
    bool validPalindrome(string s) {
        if (isPalin(s)) {
            return true;
        }
        for (int i  = 0; i < s.size(); i++) {
            if (isPalin(construct(i, s))) {
                return true;
            }
        }
        return false;

    
    }

    bool isPalin(string s) {
        string str = "";
        for (char ch : s) {
            str = ch + str;
        }
        return (str == s);
    }

    string construct(int idx, string s) {
        string returner = "";
        for (int i = 0; i < s.size(); i++) {
            if (idx != i) {
                returner += s[i];
            }
        }
        return returner;
    }
    //write normal code for checking if something is a pallindrome firstly, two methods
};
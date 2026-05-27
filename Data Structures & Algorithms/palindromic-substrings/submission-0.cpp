class Solution {
public:
    int countSubstrings(string s) {
        int returner = 0;
        for (int i = 0;  i < s.size(); i++) {
            for (int j = s.size() - 1; j >= 0; j--) {
                if (pallindrome(s,i,j)) {
                    std::cout << i << std::endl;
                    std::cout << j << std::endl;
                    returner++;
                }
            }
        }
        return returner;
    }
    bool pallindrome(string s, int start, int end) {
        if (start > end) {
            return false;
        }
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            } else {
                std::cout << "myow" << std::endl;
                return false;
            }
        }
        return true;
    }
};

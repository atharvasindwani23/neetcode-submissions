class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::map<char,bool> present;
        for (char ch : s1) {
            present[ch] = true;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (present[s2[i]]) {
                string checker = s2.substr(i, s1.size());
                string check  = s1;
                sort(checker.begin(), checker.end());
                sort(check.begin(), check.end());
                if (checker == check) {
                    return true;
                }
            }
        }
        return false;
    }
};

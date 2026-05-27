class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (string word : wordDict) {
                int len = word.size();
                if (i - len >= 0 &&
                    dp[i - len] &&
                    s.substr(i - len, len) == word) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

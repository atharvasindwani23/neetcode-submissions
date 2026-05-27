class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> present(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false); // dp[i] will be true if s[0..i-1] can be segmented
        dp[0] = true; // base case: empty string can always be segmented
        
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && present.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};

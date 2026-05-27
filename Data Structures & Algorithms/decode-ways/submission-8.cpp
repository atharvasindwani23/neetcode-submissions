class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            // single digit
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            // two digits
            if (i >= 2 &&
                (s[i - 2] == '1' ||
                (s[i - 2] == '2' && s[i - 1] < '7'))) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

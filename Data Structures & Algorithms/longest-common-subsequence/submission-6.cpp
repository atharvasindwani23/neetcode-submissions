class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m, vector<int>(n));
        //we need to return dp[0][0]
        //what are the base cases think of that
        //if it j has one character it can either be 1 or 0 that depends on smth
        bool b = false;
        for (int i = n - 1; i >= 0; i--) {
            if (text2[i] == text1[m - 1]) {
                b = true;
            } 
            if (b) {
                dp[m - 1][i] = 1;
            } else {
                dp[m - 1][i] = 0;
            }
        }
        bool c = false;
        for (int i = m - 1; i >= 0; i--) {
            if (text1[i] == text2[n - 1]) {
                c = true;
            }
            if (c) {
                dp[i][n - 1] = 1;
            } else {
                dp[i][n - 1] = 0;
            }
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    std::cout << text1[i];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

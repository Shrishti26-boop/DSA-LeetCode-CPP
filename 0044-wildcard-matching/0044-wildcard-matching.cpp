class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[j] = dp[j - 1];
            else
                break;
        }

        for (int i = 1; i <= n; i++) {
            bool prev = dp[0];
            dp[0] = false;

            for (int j = 1; j <= m; j++) {
                bool old = dp[j];

                if (p[j - 1] == '*') {
                    dp[j] = dp[j] || dp[j - 1];
                }
                else if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                    dp[j] = prev;
                }
                else {
                    dp[j] = false;
                }

                prev = old;
            }
        }

        return dp[m];
    }
};
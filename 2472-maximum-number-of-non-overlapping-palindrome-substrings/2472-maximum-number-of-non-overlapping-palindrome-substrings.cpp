class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1)
                    isPal[i][j] = true;
                else if (len == 2)
                    isPal[i][j] = (s[i] == s[j]);
                else
                    isPal[i][j] = (s[i] == s[j] && isPal[i + 1][j - 1]);
            }
        }

        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];
            for (int j = 0; j <= i - k + 1; j++) {
                if (isPal[j][i])
                    dp[i + 1] = max(dp[i + 1], dp[j] + 1);
            }
        }

        return dp[n];
    }
};
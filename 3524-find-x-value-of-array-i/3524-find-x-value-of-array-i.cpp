class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0), dp(k, 0);

        for (int num : nums) {
            int m = num % k;
            vector<long long> next(k, 0);

            next[m]++;

            for (int r = 0; r < k; r++)
                next[(r * m) % k] += dp[r];

            for (int r = 0; r < k; r++)
                ans[r] += next[r];

            dp = next;
        }

        return ans;
    }
};
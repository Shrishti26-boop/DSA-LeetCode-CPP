class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1000000007;
        vector<long long> last(26, 0);
        long long total = 1;

        for (char c : s) {
            long long cur = (2 * total - last[c - 'a'] + MOD) % MOD;
            last[c - 'a'] = total;
            total = cur;
        }

        return (total - 1 + MOD) % MOD;
    }
};
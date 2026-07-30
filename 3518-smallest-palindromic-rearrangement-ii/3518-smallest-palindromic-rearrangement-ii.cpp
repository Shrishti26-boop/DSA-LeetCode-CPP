class Solution {
public:
    long long nCr(int n, int r, long long k) {
        r = min(r, n - r);

        long long result = 1;
        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;
            if (result >= k) return k;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if (n % 2 == 1)
            mid = s[n / 2];

        vector<int> count(26, 0);

        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue;
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
            count[i] /= 2;

        int half = n / 2;

        
        long long totalWays = 1;
        int letters = half;

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                totalWays *= nCr(letters, count[i], k);
                if (totalWays >= k) break;
                letters -= count[i];
            }
        }

        if (totalWays < k)
            return "";

        string halfResult = "";

        for (int pos = 0; pos < half; pos++) {
            for (int ch = 0; ch < 26; ch++) {

                if (count[ch] == 0)
                    continue;

                count[ch]--;

                long long ways = 1;
                int remaining = 0;

                for (int c = 0; c < 26; c++)
                    remaining += count[c];

                for (int c = 0; c < 26; c++) {
                    if (count[c] > 0) {
                        ways *= nCr(remaining, count[c], k);
                        if (ways >= k)
                            break;
                        remaining -= count[c];
                    }
                }

                if (ways >= k) {
                    halfResult.push_back(char('a' + ch));
                    break;
                }

                k -= ways;
                count[ch]++;
            }
        }

        string right = halfResult;
        reverse(right.begin(), right.end());

        if (mid != ' ')
            halfResult.push_back(mid);

        return halfResult + right;
    }
};
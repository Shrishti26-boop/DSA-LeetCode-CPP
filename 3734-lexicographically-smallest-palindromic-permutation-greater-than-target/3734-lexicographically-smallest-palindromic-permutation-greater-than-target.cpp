class Solution {
public:
    string answer;
    vector<int> cnt;
    string target;
    string half;
    char mid = 0;
    int n, m;

    void fillSmallest(int pos) {
        for (int c = 0; c < 26; c++) {
            while (cnt[c] > 0) {
                half[pos++] = char('a' + c);
                cnt[c]--;
            }
        }
    }

    bool dfs(int pos, bool greaterPrefix) {
        if (greaterPrefix) {
            fillSmallest(pos);
            answer = half + (mid ? string(1, mid) : "") +
                     string(half.rbegin(), half.rend());
            return true;
        }

        if (pos == m) {
            if (n % 2) {
                if (mid < target[m]) return false;
                if (mid > target[m]) {
                    answer = half + string(1, mid) +
                             string(half.rbegin(), half.rend());
                    return true;
                }
            }

            for (int i = m - 1; i >= 0; i--) {
                char p = half[i];
                char t = target[n - 1 - i];
                if (p > t) {
                    answer = half + (mid ? string(1, mid) : "") +
                             string(half.rbegin(), half.rend());
                    return true;
                }
                if (p < t) return false;
            }
            return false;
        }

        int start = target[pos] - 'a';

        for (int c = start; c < 26; c++) {
            if (cnt[c] == 0) continue;

            cnt[c]--;
            half[pos] = char('a' + c);

            if (dfs(pos + 1, c > start)) return true;

            cnt[c]++;
        }

        return false;
    }

    string lexPalindromicPermutation(string s, string t) {
        n = s.size();
        target = t;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        int odd = 0;
        mid = 0;
        cnt.assign(26, 0);

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
            cnt[i] = freq[i] / 2;
        }

        if (odd > 1) return "";

        m = n / 2;
        half.assign(m, ' ');

        answer.clear();
        if (dfs(0, false)) return answer;
        return "";
    }
};
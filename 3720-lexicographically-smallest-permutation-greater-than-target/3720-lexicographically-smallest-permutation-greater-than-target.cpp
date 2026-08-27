class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int n = s.size();
        int m = 0;

        while (m < n && cnt[target[m] - 'a'] > 0) {
            cnt[target[m] - 'a']--;
            m++;
        }

        auto build = [&](string pref, vector<int> c) {
            for (int i = 0; i < 26; i++)
                pref.append(c[i], char('a' + i));
            return pref;
        };

        if (m < n) {
            for (int x = target[m] - 'a' + 1; x < 26; x++) {
                if (cnt[x]) {
                    cnt[x]--;
                    return build(target.substr(0, m) + char('a' + x), cnt);
                }
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            cnt[target[j] - 'a']++;
            for (int x = target[j] - 'a' + 1; x < 26; x++) {
                if (cnt[x]) {
                    cnt[x]--;
                    return build(target.substr(0, j) + char('a' + x), cnt);
                }
            }
        }

        return "";
    }
};
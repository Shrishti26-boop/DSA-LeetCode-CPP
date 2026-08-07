class Solution {
public:
    string smallestNumber(string num, long long t) {
        int need[4] = {};

        while (t % 2 == 0) {
            need[0]++;
            t /= 2;
        }
        while (t % 3 == 0) {
            need[1]++;
            t /= 3;
        }
        while (t % 5 == 0) {
            need[2]++;
            t /= 5;
        }
        while (t % 7 == 0) {
            need[3]++;
            t /= 7;
        }

        if (t != 1) return "-1";

        int f[10][4] = {
            {0,0,0,0},
            {0,0,0,0},
            {1,0,0,0},
            {0,1,0,0},
            {2,0,0,0},
            {0,0,1,0},
            {1,1,0,0},
            {0,0,0,1},
            {3,0,0,0},
            {0,2,0,0}
        };

        int A = need[0];
        int B = need[1];
        int C = need[2];
        int D = need[3];

        int SB = B + 1;
        int SC = C + 1;
        int SD = D + 1;

        auto id = [&](int a, int b, int c, int d) {
            return (((a * SB + b) * SC + c) * SD + d);
        };

        int total = (A + 1) * SB * SC * SD;

        vector<unsigned char> dp(total, 255);

        dp[id(0,0,0,0)] = 0;

        for (int a = 0; a <= A; a++) {
            for (int b = 0; b <= B; b++) {
                for (int c = 0; c <= C; c++) {
                    for (int d = 0; d <= D; d++) {

                        if (a == 0 && b == 0 && c == 0 && d == 0)
                            continue;

                        int best = 255;

                        for (int x = 2; x <= 9; x++) {
                            int na = max(0, a - f[x][0]);
                            int nb = max(0, b - f[x][1]);
                            int nc = max(0, c - f[x][2]);
                            int nd = max(0, d - f[x][3]);

                            if (dp[id(na,nb,nc,nd)] != 255) {
                                best = min(
                                    best,
                                    (int)dp[id(na,nb,nc,nd)] + 1
                                );
                            }
                        }

                        dp[id(a,b,c,d)] = best;
                    }
                }
            }
        }

        auto minDigits = [&](int a, int b, int c, int d) {
            return (int)dp[id(a,b,c,d)];
        };

        int n = num.size();

        vector<array<int,4>> pref(n + 1);
        vector<int> zeros(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            zeros[i + 1] = zeros[i];

            int x = num[i] - '0';

            if (x == 0) {
                zeros[i + 1]++;
            } else {
                for (int j = 0; j < 4; j++)
                    pref[i + 1][j] += f[x][j];
            }
        }

        int have2 = pref[n][0];
        int have3 = pref[n][1];
        int have5 = pref[n][2];
        int have7 = pref[n][3];

        if (zeros[n] == 0 &&
            have2 >= A &&
            have3 >= B &&
            have5 >= C &&
            have7 >= D) {
            return num;
        }

        for (int i = n - 1; i >= 0; i--) {

            if (zeros[i] > 0)
                continue;

            int cur = num[i] - '0';

            for (int d = cur + 1; d <= 9; d++) {

                int r2 = max(0, A - pref[i][0] - f[d][0]);
                int r3 = max(0, B - pref[i][1] - f[d][1]);
                int r5 = max(0, C - pref[i][2] - f[d][2]);
                int r7 = max(0, D - pref[i][3] - f[d][3]);

                int remaining = n - i - 1;

                if (minDigits(r2,r3,r5,r7) > remaining)
                    continue;

                string ans = num.substr(0, i);
                ans.push_back(char('0' + d));

                for (int pos = 0; pos < remaining; pos++) {

                    int left = remaining - pos - 1;

                    for (int x = 1; x <= 9; x++) {

                        int nr2 = max(0, r2 - f[x][0]);
                        int nr3 = max(0, r3 - f[x][1]);
                        int nr5 = max(0, r5 - f[x][2]);
                        int nr7 = max(0, r7 - f[x][3]);

                        if (minDigits(nr2,nr3,nr5,nr7) <= left) {
                            ans.push_back(char('0' + x));

                            r2 = nr2;
                            r3 = nr3;
                            r5 = nr5;
                            r7 = nr7;

                            break;
                        }
                    }
                }

                return ans;
            }
        }

        int len = max(n + 1, minDigits(A,B,C,D));

        string ans;

        int r2 = A;
        int r3 = B;
        int r5 = C;
        int r7 = D;

        for (int pos = 0; pos < len; pos++) {

            int remaining = len - pos - 1;

            for (int x = 1; x <= 9; x++) {

                int nr2 = max(0, r2 - f[x][0]);
                int nr3 = max(0, r3 - f[x][1]);
                int nr5 = max(0, r5 - f[x][2]);
                int nr7 = max(0, r7 - f[x][3]);

                if (minDigits(nr2,nr3,nr5,nr7) <= remaining) {
                    ans.push_back(char('0' + x));

                    r2 = nr2;
                    r3 = nr3;
                    r5 = nr5;
                    r7 = nr7;

                    break;
                }
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int sr = 0, sc = 0, idx = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') sr = i, sc = j;
                else if (classroom[i][j] == 'L') id[i][j] = idx++;
            }
        }

        int full = (1 << idx) - 1;
        int cells = m * n;
        int states = (1 << idx) * cells * (energy + 1);
        vector<char> vis(states, 0);

        auto get = [&](int r, int c) { return r * n + c; };
        auto enc = [&](int r, int c, int e, int mask) {
            return ((mask * cells + get(r, c)) * (energy + 1) + e);
        };

        queue<array<int, 5>> q;
        vis[enc(sr, sc, energy, 0)] = 1;
        q.push({sr, sc, energy, 0, 0});

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c, e, mask, d] = q.front();
            q.pop();

            if (mask == full) return d;
            if (e == 0) continue;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (classroom[nr][nc] == 'X') continue;

                int ne = e - 1;
                if (classroom[nr][nc] == 'R') ne = energy;

                int nmask = mask;
                if (classroom[nr][nc] == 'L')
                    nmask |= 1 << id[nr][nc];

                int code = enc(nr, nc, ne, nmask);
                if (!vis[code]) {
                    vis[code] = 1;
                    q.push({nr, nc, ne, nmask, d + 1});
                }
            }
        }

        return -1;
    }
};
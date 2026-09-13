class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> a, b;
        int n = img1.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) a.push_back({i, j});
                if (img2[i][j]) b.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;
        int ans = 0;

        for (auto &p1 : a) {
            for (auto &p2 : b) {
                ans = max(ans, ++mp[{p2.first - p1.first, p2.second - p1.second}]);
            }
        }

        return ans;
    }
};
class Solution {
public:
    struct Node {
        long long sum;
        vector<int> idx;
    };

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};

        sort(a.begin(), a.end());

        vector<long long> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = a[i][0];

        vector<int> nxt(n);
        for (int i = 0; i < n; i++)
            nxt[i] = upper_bound(starts.begin(), starts.end(), a[i][1]) - starts.begin();

        vector<vector<Node>> dp(n + 1, vector<Node>(5));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                Node skip = dp[i + 1][k];
                Node take = dp[nxt[i]][k - 1];
                take.sum += a[i][2];
                take.idx.insert(take.idx.begin(), (int)a[i][3]);
                sort(take.idx.begin(), take.idx.end());

                if (take.sum > skip.sum)
                    dp[i][k] = take;
                else if (take.sum < skip.sum)
                    dp[i][k] = skip;
                else
                    dp[i][k] = take.idx < skip.idx ? take : skip;
            }
        }

        return dp[0][4].idx;
    }
};
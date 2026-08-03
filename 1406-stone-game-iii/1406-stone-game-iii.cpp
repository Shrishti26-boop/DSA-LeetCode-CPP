class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& stones, int i) {

        if(i >= n)
            return 0;

        if(dp[i] != INT_MIN)
            return dp[i];

        int result = INT_MIN;

        result = max(result,
                     stones[i] - solve(stones, i + 1));

        if(i + 1 < n)
            result = max(result,
                         stones[i] + stones[i + 1] - solve(stones, i + 2));

        if(i + 2 < n)
            result = max(result,
                         stones[i] + stones[i + 1] + stones[i + 2]
                         - solve(stones, i + 3));

        return dp[i] = result;
    }

    string stoneGameIII(vector<int>& stones) {

        n = stones.size();

        dp.assign(n, INT_MIN);

        int diff = solve(stones, 0);

        if(diff > 0)
            return "Alice";
        else if(diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};
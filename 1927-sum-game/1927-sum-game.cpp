class Solution {
public:
    bool sumGame(string num) {
        int n = num.size(), m = n / 2;
        int leftSum = 0, rightSum = 0, leftQ = 0, rightQ = 0;

        for (int i = 0; i < m; i++) {
            if (num[i] == '?') leftQ++;
            else leftSum += num[i] - '0';
        }

        for (int i = m; i < n; i++) {
            if (num[i] == '?') rightQ++;
            else rightSum += num[i] - '0';
        }

        if ((leftQ + rightQ) % 2) return true;

        return leftSum - rightSum != (rightQ - leftQ) / 2 * 9;
    }
};
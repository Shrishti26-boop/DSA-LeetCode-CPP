class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        for (auto& seat : reservedSeats) {
            int r = seat[0], c = seat[1];
            if (c >= 2 && c <= 9)
                mp[r] |= (1 << c);
        }

        int ans = (n - mp.size()) * 2;

        for (auto& [r, mask] : mp) {
            bool left = true, mid = true, right = true;

            for (int c = 2; c <= 5; c++)
                if (mask & (1 << c)) left = false;

            for (int c = 4; c <= 7; c++)
                if (mask & (1 << c)) mid = false;

            for (int c = 6; c <= 9; c++)
                if (mask & (1 << c)) right = false;

            if (left && right)
                ans += 2;
            else if (left || mid || right)
                ans += 1;
        }

        return ans;
    }
};
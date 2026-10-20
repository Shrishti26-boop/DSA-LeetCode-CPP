class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        auto isSortable = [&](int k) -> bool {
            int prevMax = INT_MIN;

            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;
                int drops = 0;
                int dropIdx = -1;

                for (int i = start; i < end; i++) {
                    if (nums[i] > nums[i + 1]) {
                        drops++;
                        dropIdx = i;
                    }
                }

                if (drops > 1)
                    return false;

                int mn, mx;

                if (drops == 0) {
                    mn = nums[start];
                    mx = nums[end];
                } else {
                    if (nums[end] > nums[start])
                        return false;

                    mn = nums[dropIdx + 1];
                    mx = nums[dropIdx];
                }

                if (mn < prevMax)
                    return false;

                prevMax = mx;
            }

            return true;
        };

        for (int k = 1; k <= n; k++) {
            if (n % k == 0 && isSortable(k))
                ans += k;
        }

        return ans;
    }
};
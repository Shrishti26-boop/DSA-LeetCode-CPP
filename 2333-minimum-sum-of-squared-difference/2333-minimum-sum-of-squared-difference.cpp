
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        long long k = 1LL * k1 + k2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int low = 0, high = 100000;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int x : diff) {
                if (x > mid)
                    need += x - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        for (int x : diff) {
            int reduced = min(x, low);
            ans += 1LL * reduced * reduced;
            k -= x - reduced;
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] >= low && low > 0) {
                ans -= 1LL * low * low;
                ans += 1LL * (low - 1) * (low - 1);
                k--;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int l = min(minIdx, maxIdx);
        int r = max(minIdx, maxIdx);

        int front = r + 1;
        int back = n - l;
        int both = (l + 1) + (n - r);

        return min({front, back, both});
    }
};
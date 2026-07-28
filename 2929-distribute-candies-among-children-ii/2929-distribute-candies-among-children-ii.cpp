class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans =0;
        for(int i=0;i<=min(limit,n);i++){
            int remaining =n-i;
            int left=max(0,remaining-limit);
            int right=min(limit,remaining);
            if(left<=right){
                ans+=(right-left+1);
            }
        }
        return ans;
    }
};
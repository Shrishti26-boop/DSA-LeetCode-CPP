class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int i=0;i<=limit;i++){
            int remaining=n-i;
            int left=max(0,remaining-limit);
            int right=min(limit,remaining);
            if(left<=right){
                ans+=right-left+1;
            }
        }
        return ans;
    }
};
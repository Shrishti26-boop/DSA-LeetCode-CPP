class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(),nums.end());
       int ans=0;
       int i=0;
       while(i<n){
        int j=i;
        while(j<n&&nums[i]==nums[j]){
            j++;
        }
        int freq=j-i;
        ans+=(freq*(freq-1)/2);
        i=j;
       }
       return ans;
    }
};
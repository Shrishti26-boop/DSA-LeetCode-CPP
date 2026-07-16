class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
       unordered_map<int,vector<int>>mp;
       int ans=0;
       for(int j=0;j<nums.size();j++){
        for(int i:mp[nums[j]]){
            if((i*j)%k==0){
                ans++;
            }
        }
        mp[nums[j]].push_back(j);
       }
       return ans;
    }
};
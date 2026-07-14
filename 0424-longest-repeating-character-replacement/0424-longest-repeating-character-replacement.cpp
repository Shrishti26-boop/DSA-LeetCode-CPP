class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.length();
       unordered_map<char,int>mp;
       int left=0;
       int maxFq=0;
       int ans=0;
       for(int right=0;right<n;right++){
        mp[s[right]]++;
        maxFq=max(maxFq,mp[s[right]]);
        while((right-left+1)-maxFq>k){
            mp[s[left]]--;
            left++;
        }
        ans=max(ans,right-left+1);
       }
       return ans;
    }
};
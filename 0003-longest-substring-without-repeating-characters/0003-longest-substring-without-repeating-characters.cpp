class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int>last(256,-1);
       int n = s.length();
       int left=0;
       int maxlen=0;
       for(int right=0;right<n;right++){
        char c=s[right];
        if(last[c]>=left){
            left=last[c]+1;
        }
        last[c]=right;
        maxlen=max(maxlen,right-left+1);
       }
       return maxlen;
    }
};
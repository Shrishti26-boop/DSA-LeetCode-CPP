class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int c=0;
      int maxlen=0;
      int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]==1){
           c++;
           maxlen=max(maxlen,c);
        }
        else {
        c=0;
        }
      }  
      return maxlen;
    }
};
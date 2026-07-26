class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
             sort(nums.begin(),nums.end());
             if (nums.empty()) return 0;
             int c=1,x=1;
        for(int i =1;i<nums.size();i++){
         if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]-nums[i-1]==1){
                c++;
            }
            else{
                x=max(x,c);
                c=1;
            }
        }
        return max(x,c);
    }
};
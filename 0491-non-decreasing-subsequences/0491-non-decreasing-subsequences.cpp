class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans){
        if(curr.size()>=2){
            ans.push_back(curr);
        }
        unordered_set<int>used;
        for(int i=index;i<nums.size();i++){
            
            if(used.count(nums[i])) continue;

            if(curr.empty() || nums[i]>=curr.back()){
            used.insert(nums[i]);
            curr.push_back(nums[i]);
            solve(i+1,nums,curr,ans);
            curr.pop_back();
        }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
       solve(0,nums,curr,ans);
       return ans; 
    }
};
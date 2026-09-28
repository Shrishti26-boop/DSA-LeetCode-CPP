class Solution {
public:
    void solve(int start,int sum,int target,vector<int>& candidates,vector<int>& curr,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target) return;
        for(int i=start;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            solve(i,sum+candidates[i],target,candidates,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int> curr;
       vector<vector<int>>ans ;
       solve(0,0,target,candidates,curr,ans);
       return ans;
    }
};
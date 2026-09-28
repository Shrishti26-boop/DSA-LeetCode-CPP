class Solution {
public:
    void solve(int start,int sum,int target,vector<int>& candidates,vector<int>& curr,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        if(sum>target) return;
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            solve(i+1,sum+candidates[i],target,candidates,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        solve(0,0,target,candidates,curr,ans);
        return ans;
    }
};
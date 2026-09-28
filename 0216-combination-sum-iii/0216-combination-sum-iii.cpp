class Solution {
public:
    void solve(int start,int sum,int k,int n,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()==k){
            if(sum==n){
                ans.push_back(curr);
                return;
            }
        }
        if(sum>n) return;
        for(int i=start;i<=9;i++){
            curr.push_back(i);
            solve(i+1,sum+i,k,n,curr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(1,0,k,n,curr,ans);
        return ans;
    }
};
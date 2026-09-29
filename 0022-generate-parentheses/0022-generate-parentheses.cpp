class Solution {
public:
    vector<string> ans;
    void solve(int open,int close,int n,string curr){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            solve(open+1,close,n,curr);
            curr.pop_back();
        }
        if(close<open){
            curr.push_back(')');
            solve(open,close+1,n,curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans;
    }
};
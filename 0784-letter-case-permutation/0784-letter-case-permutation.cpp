class Solution {
public:
    void solve(int index, string &s,vector<string>&ans){
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        if(isalpha(s[index])){
            s[index]=tolower(s[index]);
            solve(index+1,s,ans);

            s[index]=toupper(s[index]);
            solve(index+1,s,ans);
        }
        else{
            solve(index+1,s,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
       vector<string>ans;
       solve(0,s,ans);
       return ans;
    }
};
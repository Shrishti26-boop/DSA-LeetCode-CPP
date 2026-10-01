class Solution {
public:
    bool isPalindrome(string &s,int l,int r){
          while(l<r){
            if(s[l]!=s[r])
                return false;
                l++;
                r--;
            
          } 
           return true;
    }
    void solve(int index,string &s,vector<string>&path,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int j =index;j<s.size();j++){
            if(isPalindrome(s,index,j)){
                path.push_back(s.substr(index,j-index+1));
                solve(j+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        vector<vector<string>>ans;
        solve(0,s,path,ans);
        return ans;
    }
};
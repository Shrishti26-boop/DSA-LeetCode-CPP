class Solution {
public:
    
    bool isValid(string &str){
        int c=0;
        for(char &ch:str){
            if(ch=='('){
                c++;
            }
            else {
                c--;
                }
            if(c<0) return false;
        }
        return c==0;
    }

    vector<string>result;

    void solve(string &curr,int n){
        if(curr.length()==2*n){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return result;
    }
};
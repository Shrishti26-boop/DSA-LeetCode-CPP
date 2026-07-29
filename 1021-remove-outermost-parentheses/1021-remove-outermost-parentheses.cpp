class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans="";
        for(char ch:s){
            if(ch=='('){
                if(c>0)
                ans+=ch;
                c++;
            }
            else{
                c--;
                if(c>0)
                ans+=ch;
            }
        }
        return ans;
    }
};
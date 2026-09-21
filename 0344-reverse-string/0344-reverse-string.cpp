class Solution {
public:
    void reverseS(int i,int j,vector<char>&s){
        if(i>=j) return;
        swap(s[i],s[j]);
        reverseS(i+1,j-1,s);
    }
    void reverseString(vector<char>& s) {
        reverseS(0,s.size()-1,s);
    }
};
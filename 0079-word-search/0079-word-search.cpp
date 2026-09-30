class Solution {
public:

    bool solve(int row,int col,int index,string & word,vector<vector<char>>& board){

        if(index==word.size()) 
        return true;

        if(row<0||col<0||row>=board.size()||col>=board[0].size())
        return false;

        if(board[row][col]!=word[index])
        return false;

        char temp=board[row][col];
        board[row][col]='#';
        
        bool found=
           solve(row+1,col,index+1,word,board)||
           solve(row-1,col,index+1,word,board)||
           solve(row,col+1,index+1,word,board)||
           solve(row,col-1,index+1,word,board);
        board[row][col]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
       for(int i =0;i<board.size();i++) {
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]==word[0]){
                if(solve(i,j,0,word,board)){
                     return true;
                }
            }
        }
       }
       return false;
    }
};
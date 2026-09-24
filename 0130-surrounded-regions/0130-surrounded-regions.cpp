class Solution {
public:
    int m, n;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O')
            return;

        board[i][j] = '#';

        for (auto &d : dir)
            dfs(board, i + d[0], j + d[1]);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        // Check upper column
        int i = row;
        int j = col;

        while (i >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
        }

        // Check upper-left diagonal
        i = row;
        j = col;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row;
        j = col;

        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }
        return true;
    }

    void solve(int n, int row, vector<string>& board,
               vector<vector<string>>& ans) {
        if (n == row) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(row, j, board, n)) {
                board[row][j] = 'Q';
                solve(n, row + 1, board, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        int row = 0;
        solve(n, row, board, ans);
        return ans;
    }
};
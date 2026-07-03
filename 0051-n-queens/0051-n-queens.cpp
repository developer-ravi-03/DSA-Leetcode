class Solution {
public:

    bool isSafe(int row,int col,vector<string>& board,int n){
        //check horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q'){
                return false;
            }
        }

        //check vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }

        //left diaginal
        for(int i=row, j=col; i>=0 && j>=0;j--,i--){
            if(board[i][j]=='Q'){
                return false;
            }
        }

        //right diaginal
        for(int i=row, j=col; i>=0 && j<n;j++,i--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }

    void solve(int n,int row,vector<string>& board,vector<vector<string>> &ans){
        if(n==row){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
            if(isSafe(row,j,board,n)){
                board[row][j]='Q';
                solve(n,row+1,board,ans);
                board[row][j]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>  board(n,string(n,'.'));
        int row=0;
        solve(n,row,board,ans);
        return ans;
    }
};
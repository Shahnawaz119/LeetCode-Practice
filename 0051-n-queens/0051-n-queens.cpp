class Solution {
public:
    bool check(vector<string>&board,int i,int j,int n){
        int row=i;
        int col=j;
        while(row>-1 && col>-1){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=i;
        col=j;
        while(row>-1 && col<n){
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void solve(vector<string>&board,vector<vector<string>>&ans,vector<int>&column,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }
        for(int j=0; j<n; j++){
            if(column[j]==0 && check(board,row,j,n)){
                column[j]=1;
                board[row][j]='Q';
                solve(board,ans,column,row+1,n);
                column[j]=0;
                board[row][j]='.';
            } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                board[i].push_back('.');
            }
        }
        vector<int> column(n,0);
        solve(board,ans,column,0,n);
        return ans;
    }
};
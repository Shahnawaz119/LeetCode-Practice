class Solution {
public:
    bool check(vector<string>&Board,int i,int j,int n){
        int row=i,col=j;
        while(row>-1 && col>-1){
            if(Board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }
        row=i,col=j;
        while(row>-1 && col<n){
            if(Board[row][col]=='Q'){
                return false;
            }
            row--;
            col++;
        }

        return true;
    }
    void find(int n,vector<vector<string>>&ans,vector<int>&column,vector<string>&Board,int row){
        if(row==n){
            ans.push_back(Board);
            return;
        }
        for(int j=0; j<n; j++){
            if(column[j]==0 && check(Board,row,j,n)){
                column[j]=1;
                Board[row][j]='Q';
                find(n,ans,column,Board,row+1);
                Board[row][j]='.';
                column[j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> Board(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                Board[i].push_back('.');
            }
        }
        vector<int>column(n,0);
        find(n,ans,column,Board,0);
        return ans;
    }
};
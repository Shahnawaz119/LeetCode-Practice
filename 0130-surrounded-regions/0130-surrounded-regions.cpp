class Solution {
public:
    void DFS(vector<vector<char>>&board,int i,int j,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c || board[i][j]!='O'){
            return;
        }
        board[i][j]='T';
        DFS(board,i,j+1,r,c);
        DFS(board,i-1,j,r,c);
        DFS(board,i,j-1,r,c);
        DFS(board,i+1,j,r,c);
    }
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r==0){
            return;
        }
        int c=board.size();
        for(int i=0; i<r; i++){
            DFS(board,i,0,r,c);
            DFS(board,i,c-1,r,c);
        }
        for(int j=0; j<c; j++){
            DFS(board,0,j,r,c);
            DFS(board,r-1,j,r,c);
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};
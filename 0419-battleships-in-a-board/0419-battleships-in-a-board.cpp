class Solution {
public:
    void DFS(vector<vector<char>> &board,int i,int j,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c || board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        DFS(board,i,j+1,r,c);
        DFS(board,i-1,j,r,c);
        DFS(board,i,j-1,r,c);
        DFS(board,i+1,j,r,c);
    }
    int countBattleships(vector<vector<char>>& board) {
        int r=board.size();
        if(r==0){
            return 0;
        }
        int c=board[0].size();
        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j]=='X'){
                    count++;
                    DFS(board,i,j,r,c);
                }
            }
        }
        return count;
    }
};
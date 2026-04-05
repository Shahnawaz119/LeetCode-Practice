class Solution {
public:
    int n,m;
    vector<int> dx={0,1,0,-1};
    vector<int> dy={1,0,-1,0};
    bool solve(vector<vector<char>> &board,string &word,int idx,int i,int j){
        if(word.length()==idx){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char ch=board[i][j];
        board[i][j]='$';
        for(int k=0; k<4; k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(solve(board,word,idx+1,x,y)){
                return true;
            }
        }
        board[i][j]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && solve(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};
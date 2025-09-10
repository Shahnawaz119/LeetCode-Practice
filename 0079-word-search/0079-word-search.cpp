class Solution {
public:
    vector<int> dirX={0,-1,0,1};
    vector<int> dirY={1,0,-1,0};
    bool solve(vector<vector<char>>&board,int i,int j,int n,int m,int idx,string word){
        if(word.length()==idx){
            return true;
        }
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='$';
        for(int k=0; k<4; k++){
            int x=i+dirX[k];
            int y=j+dirY[k];
            if(solve(board,x,y,n,m,idx+1,word)){
                return true;
            }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board,string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0] && solve(board,i,j,n,m,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
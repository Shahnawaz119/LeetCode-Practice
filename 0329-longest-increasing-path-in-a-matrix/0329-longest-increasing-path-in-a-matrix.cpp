class Solution {
public:
    int DFS(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=matrix.size();
        int c=matrix[0].size();
        int maxPath=1;
        vector<int> dirX={1,0,-1,0};
        vector<int> dirY={0,-1,0,1};
        for(int d=0; d<4; d++){
            int ni=i+dirX[d];
            int nj=j+dirY[d];
            if(ni>=0 && nj>=0 && ni<r && nj<c && matrix[i][j]>matrix[ni][nj]){
                maxPath=max(maxPath,1+DFS(matrix,ni,nj,dp));
            }
        }
        dp[i][j]=maxPath;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        if(r==0){
            return 0;
        }
        int c=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(r,vector<int> (c,-1));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans=max(ans,DFS(matrix,i,j,dp));
            }
        }
        return ans;
    }
};
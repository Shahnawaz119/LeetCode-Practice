class Solution {
public:
    int const MOD=1e9+7;
    int DFS(vector<vector<int>> &grid,int i,int j,vector<vector<long long>> &dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int r=grid.size();
        int c=grid[0].size();
        long long ans=1;
        vector<int> dirX={1,0,-1,0};
        vector<int> dirY={0,-1,0,1};
        for(int d=0; d<4; d++){
            int ni=i+dirX[d];
            int nj=j+dirY[d];
            if(ni>=0 && nj>=0 && ni<r && nj<c && grid[i][j]<grid[ni][nj]){
                ans=(ans+DFS(grid,ni,nj,dp))%MOD;
            }
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int countPaths(vector<vector<int>>& grid) {
        int r=grid.size();
        if(r==0){
            return 0;
        }
        int c=grid[0].size();
        long long result=0;
        vector<vector<long long>> dp(r,vector<long long> (c,-1));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                result=(result+DFS(grid,i,j,dp))%MOD;
            }
        }
        return result;
    }
};
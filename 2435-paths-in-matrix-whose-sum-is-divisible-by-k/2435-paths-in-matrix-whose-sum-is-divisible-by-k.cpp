class Solution {
public:
    int m,n;
    const int mod=1e9+7;
    int solve(int i,int j,int currSum,int k,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            if((currSum+grid[i][j])%k==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][j][currSum]!=-1){
            return dp[i][j][currSum];
        }
        int rightWay=solve(i,j+1,(currSum+grid[i][j])%k,k,grid,dp);
        int downWay=solve(i+1,j,(currSum+grid[i][j])%k,k,grid,dp);
        return dp[i][j][currSum]=(rightWay+downWay)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int> (k,-1)));
        return solve(0,0,0,k,grid,dp);
    }
};
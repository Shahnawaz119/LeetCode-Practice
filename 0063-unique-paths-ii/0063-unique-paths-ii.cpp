class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        if(arr[0][0]==1 || arr[n-1][m-1]==1){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        dp[1][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(arr[i-1][j-1]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
class Solution {
public:
    int t[101][101];
    int totalWay(vector<vector<int>> &arr ,int i,int j,int n,int m){
        if(i>=n || j>=m || arr[i][j]==1){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        int way1=totalWay(arr,i,j+1,n,m);
        int way2=totalWay(arr,i+1,j,n,m);
        t[i][j]=way1+way2;
        return t[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        memset(t,-1,sizeof(t));
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]){
            return 0;
        }
        int result=totalWay(obstacleGrid,0,0,n,m);
        return result;
    }
};
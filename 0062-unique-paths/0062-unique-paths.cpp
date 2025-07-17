class Solution {
public:
    int uniquePaths(int m, int n) {
    //    int t=n+m-2;
    //    int k=min(m-1,n-1);
    //    long result=1;
    //    for(int i=1; i<=k; i++){
    //     result=result*(t-k+i)/i;
    //    } 
    //    return result;
        vector<vector<int>> arr(m,vector<int> (n,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
            }
        }
        return arr[m-1][n-1];
    }
};
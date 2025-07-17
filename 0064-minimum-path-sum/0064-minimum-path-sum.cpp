class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int j=1; j<m; j++){
            arr[0][j]=arr[0][j]+arr[0][j-1];
        }
        for(int i=1; i<n; i++){
            arr[i][0]=arr[i][0]+arr[i-1][0];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                arr[i][j]=min((arr[i-1][j]+arr[i][j]),(arr[i][j-1]+arr[i][j]));
            }
        }
        return arr[n-1][m-1];
    }
};
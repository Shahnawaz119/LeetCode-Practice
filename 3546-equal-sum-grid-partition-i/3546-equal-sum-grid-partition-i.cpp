class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<ll> rowSum(n,0);
        vector<ll> colSum(m,0);
        ll totalSum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                totalSum+=grid[i][j];
                rowSum[i]+=grid[i][j];
                colSum[j]+=grid[i][j];
            }
        }

        if(totalSum%2!=0){
            return false;
        }
        ll upper=0;
        for(int i=0; i<n-1; i++){
            upper+=rowSum[i];
            if(upper==totalSum-upper){
                return true;
            }
        }
        ll left=0;
        for(int i=0; i<m-1; i++){
            left+=colSum[i];
            if(left==totalSum-left){
                return true;
            }
        }
        return false;
    }
};
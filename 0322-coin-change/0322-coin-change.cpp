class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>> arr(n+1,vector<long long> (amount+1,0));
        for(int i=1; i<=amount; i++){
            arr[0][i]=INT_MAX;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(coins[i-1]>j){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=min(arr[i-1][j],1+arr[i][j-coins[i-1]]);
                }
            }
        }
        return (arr[n][amount]==INT_MAX) ? -1 : arr[n][amount];
    }
};
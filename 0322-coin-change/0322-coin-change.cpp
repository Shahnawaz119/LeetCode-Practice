class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>> ans(n+1,vector<long long> (amount+1,0));
        for(int i=1; i<=amount; i++){
            ans[0][i]=INT_MAX;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(coins[i-1]>j){
                    ans[i][j]=ans[i-1][j];
                }else{
                    ans[i][j]=min(ans[i-1][j],1+ans[i][j-coins[i-1]]);
                }
            }
        }
        return (ans[n][amount]==INT_MAX) ? -1 : ans[n][amount];
    }
};
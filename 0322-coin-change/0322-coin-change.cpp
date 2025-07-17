class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int n=coins.size();
        sort(coins.begin(),coins.end());
        int ans=0;
        for(int i=n-1; i>=0 && amount>0; i-- ){
            if(amount>=coins[i]){
                ans+=amount/coins[i];
                amount=amount%coins[i];
            }
        }
        if(amount>0){
            return -1;
        }
        return ans;
    }
};
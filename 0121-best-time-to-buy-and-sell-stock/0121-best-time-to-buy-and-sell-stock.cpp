class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> buy(n,INT_MAX);
        for(int i=1; i<n; i++){
            buy[i]=min(buy[i-1],prices[i-1]);
        }
        int profit=0;
        for(int i=0; i<n; i++){
            int currPro=prices[i]-buy[i];
            profit=max(profit,currPro);
        }
        return profit;
    }
};
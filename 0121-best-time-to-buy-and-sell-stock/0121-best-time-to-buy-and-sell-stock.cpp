class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prev=prices[0];
        int profit=0;
        for(int i=1; i<n; i++){
            prev=min(prev,prices[i]);
            profit=max(profit,prices[i]-prev);
        }
        return profit;
    }
};
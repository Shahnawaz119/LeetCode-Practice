class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> bestBuy;
        bestBuy.push_back(INT_MAX);
        for(int i=1; i<n; i++){
            bestBuy.push_back(min(bestBuy[i-1],prices[i-1]));
        }
        int maxProfit=0;
        for(int i=0; i<n; i++){
            int currProfit=prices[i]-bestBuy[i];
            maxProfit=max(maxProfit,currProfit);
        }
        return maxProfit;
    }
    
};
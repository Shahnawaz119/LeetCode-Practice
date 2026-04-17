class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prev=prices[0];
        int result=0;
        for(int i=1; i<n; i++){
            prev=min(prev,prices[i]);
            result=max(result,prices[i]-prev);
        }
        return result;
    }
};
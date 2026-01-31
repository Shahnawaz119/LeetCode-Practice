class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n=prices.size();
        vector<int> nse(n);
        for(int i=n-1; i>=0; i--){
            int curr=prices[i];
            while(!st.empty() && curr<st.top()){
                st.pop();
            }
            if(st.empty()){
                nse[i]=0;
            }else{
                nse[i]=st.top();
            }
            st.push(curr);
        }
        for(int i=0; i<n; i++){
            prices[i]=prices[i]-nse[i];
        }
        return prices;
    }
};
class Solution {
public:
    int n;
    unordered_set<string> st;
    int solve(int idx,string &s,vector<int> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        string temp="";
        int minExtra=n;
        for(int i=idx; i<n; i++){
            temp.push_back(s[i]);
            int currExtra=(st.find(temp)==st.end())?temp.length() : 0;
            int nextExtra=solve(i+1,s,dp);
            int totalExtra=currExtra + nextExtra;
            minExtra=min(minExtra,totalExtra);
        }
        return dp[idx]=minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n=s.size();
        for(string &word:dictionary){
            st.insert(word);
        }
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
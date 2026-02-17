class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
    bool solve(string &s,int i){
        if(i==s.length()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        string temp="";
        for(int j=i; j<s.length(); j++){
            temp+=s[j];
            if(st.find(temp)!=st.end()){
                if(solve(s,j+1)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.length(),-1);
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        return solve(s,0);
    }
};
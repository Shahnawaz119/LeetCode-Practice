class Solution {
public:
    int lcmRecursionWithMemo(string str1,string str2,vector<vector<int>> &dp){
        if(str1.length()==0 || str2.length()==0){
            return 0;
        }
        int n=str1.length();
        int m=str2.length();
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(str1[n-1]==str2[m-1]){
            dp[n][m]=1+lcmRecursionWithMemo(str1.substr(0,n-1),str2.substr(0,m-1),dp);
        }else{
            int ans1=lcmRecursionWithMemo(str1.substr(0,n-1),str2,dp);
            int ans2=lcmRecursionWithMemo(str1,str2.substr(0,m-1),dp);
            dp[n][m]=max(ans1,ans2);
        }
        return dp[n][m];
    }
    int longestCommonSubsequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        return lcmRecursionWithMemo(str1,str2,dp);
    }
};
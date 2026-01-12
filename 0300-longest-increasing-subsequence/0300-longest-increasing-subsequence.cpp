class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> nums1(s.begin(),s.end());
        sort(nums1.begin(),nums1.end());
        int n=nums.size();
        int m=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(nums[i-1]==nums1[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            } 
        }
        return dp[n][m];
    }
};
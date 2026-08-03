class Solution {
public:
    int solve(int i,int j,vector<int>&nums,vector<int>&nums1,vector<vector<int>>&dp){
        if(i==nums.size() || j==nums1.size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(nums[i]==nums1[j]){
            return dp[i][j]=1+solve(i+1,j+1,nums,nums1,dp);
        }

        return dp[i][j]=max(solve(i+1,j,nums,nums1,dp),solve(i,j+1,nums,nums1,dp));
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> nums1(s.begin(),s.end());
        sort(nums1.begin(),nums1.end());
        int m=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,nums,nums1,dp);
    }
};
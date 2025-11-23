class Solution {
public:
    int solve(int i,int rem,vector<int> &nums,vector<vector<int>> &dp){
        if(i>=nums.size()){
            if(rem==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[i][rem]!=-1){
            return dp[i][rem];
        }
        int take=nums[i]+solve(i+1,(nums[i]+rem)%3,nums,dp);
        int skip=solve(i+1,rem,nums,dp);
        dp[i][rem]=max(take,skip);
        return dp[i][rem];
    }
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
};
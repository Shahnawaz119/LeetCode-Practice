class Solution {
public:
    int dp[201][1001];
    int solve(vector<int>&nums,int target,int idx){
        if(target<0 || idx>=nums.size()){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int take_idx=solve(nums,target-nums[idx],0);
        int reject_idx=solve(nums,target,idx+1);
        return dp[idx][target]=take_idx+reject_idx;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};
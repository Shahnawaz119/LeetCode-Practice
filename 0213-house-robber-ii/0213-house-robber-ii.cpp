class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> dp(nums.size()-1);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2; i<nums.size()-1; i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        vector<int> dp1(nums.size()-1);
        dp1[0]=nums[1];
        dp1[1]=max(nums[1],nums[2]);
        for(int i=2; i<nums.size()-1; i++){
            dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i+1]);
        }
        
        return max(dp[dp.size()-1],dp1[dp.size()-1]);
    }
};
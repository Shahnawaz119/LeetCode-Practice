class Solution {
public:
    int t[201][1001];
    int solve(vector<int>&nums,int tar,int idx){
        if(tar<0 || idx>=nums.size()){
            return 0;
        }
        if(tar==0){
            return 1;
        }
        if(t[idx][tar]!=-1){
            return t[idx][tar];
        }
        int take_idx=solve(nums,tar-nums[idx],0);
        int reject_idx=solve(nums,tar,idx+1);
        t[idx][tar]=take_idx + reject_idx;
        return t[idx][tar];
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,target,0);

    }
};
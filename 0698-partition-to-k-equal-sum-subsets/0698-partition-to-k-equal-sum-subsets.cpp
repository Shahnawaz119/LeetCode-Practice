class Solution {
public:
    int target=0;
    bool rec(vector<int>&nums,int k,int currSum,vector<bool>&vis,int idx){
        if(k==1){
            return true;
        }
        if(currSum==target){
            return rec(nums,k-1,0,vis,0);
        }
        for(int i=idx; i<nums.size(); i++){
            if(vis[i]) continue;
            if(nums[i]+currSum>target){
                break;
            }
            vis[i]=true;
            if(rec(nums,k,currSum+nums[i],vis,i+1)){
                return true;
            }
            vis[i]=false;
            if(currSum==0){
                break;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0; i<nums.size(); i++){
            totalSum+=nums[i];
        }
        if(totalSum%k!=0){
            return false;
        }
        target=totalSum/k;
        vector<bool> vis(n,false);
        sort(nums.begin(),nums.end());
        return rec(nums,k,0,vis,0);

    }
};
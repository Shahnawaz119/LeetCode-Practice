class Solution {
public:
    vector<vector<int>> ans;
    void twoSum(vector<int>&nums,int target,int i,int j){
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<target){
                i++;
            }else if(sum>target){
                j--;
            }else{
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                ans.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int val=nums[i];
            int target=-val;
            twoSum(nums,target,i+1,n-1);
        }
        return ans;
    }
};
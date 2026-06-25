class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&nums,int tar,int i,int j){
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<tar){
                i++;
            }else if(sum>tar){
                j--;
            }else{
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                ans.push_back({-tar,nums[i],nums[j]});\
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int k=0; k<n; k++){
            if(k>0 && nums[k]==nums[k-1]){
                continue;
            }
            int tar=-nums[k];
            solve(nums,tar,k+1,n-1);
        }
        return ans;
    }
};
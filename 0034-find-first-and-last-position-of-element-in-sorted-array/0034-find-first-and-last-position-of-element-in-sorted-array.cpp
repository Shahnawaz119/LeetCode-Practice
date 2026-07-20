class Solution {
public:
    int start(vector<int>&nums,int target){
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                j=mid-1;
                ans=mid;
            }else if(nums[mid]<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    int last(vector<int>&nums,int target){
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                ans=mid;
                i=mid+1;
            }else if(nums[mid]<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {start(nums,target),last(nums,target)};
    }
};
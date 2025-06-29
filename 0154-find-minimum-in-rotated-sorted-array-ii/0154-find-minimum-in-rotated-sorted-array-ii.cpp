class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(nums[mid]==nums[i] && nums[j]==nums[mid]){
                i++;
                j--;
                continue;
            }
            if(nums[mid]>nums[j]){
                i=mid+1;
            }else{
                j=mid;
            }
        }
        return nums[i];
    }
};
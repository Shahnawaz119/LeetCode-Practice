class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int left=0;
        int right=0;
        int size=INT_MAX;
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                size=min(size,(right-left+1));
                sum=sum-nums[left];
                left++;
            }
            right++;
        }
        return size==INT_MAX?0:size;
    }
};
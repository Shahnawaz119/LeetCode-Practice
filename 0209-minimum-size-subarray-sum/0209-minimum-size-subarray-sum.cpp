class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        vector<int> prefixSum(n);
        prefixSum[0]=nums[0];
        int totalSum=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==target){
                return 1;
            }
            prefixSum[i]=prefixSum[i-1]+nums[i];
            totalSum+=nums[i];
        }
        if(totalSum<target){
            return 0;
        }
        int left=0;
        int right=0;
        int minLen=INT_MAX;
        while(right<n){
            if(prefixSum[right]>=target){
                minLen=min(minLen,right-left+1);
                while(left<=right && prefixSum[right]-prefixSum[left]>=target){
                    left++;
                }
                minLen=min(minLen,right-left+1);
            }
            right++;
        }
        return minLen;
    }
};
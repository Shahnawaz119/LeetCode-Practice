class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxCount=0;
        int start=0;
        int zeroCount=0;
        for(int end=0; end<n; end++){
            if(nums[end]==0){
                zeroCount++;
            }
            while(zeroCount>1){
                if(nums[start]==0){
                    zeroCount--;
                }
                start++;
            }
            maxCount=max(maxCount,end-start);
        }
        return maxCount;
    }
};
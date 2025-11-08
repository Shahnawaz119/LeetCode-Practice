class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int maxSum=0,currSum=0,right=0,left=0;
        while(right<nums.size()){
            if(s.find(nums[right])==s.end()){
                currSum+=nums[right];
                s.insert(nums[right]);
                maxSum=max(maxSum,currSum);
                right++;
            }else{
                currSum=currSum-nums[left];
                s.erase(nums[left]);
                left++;
            }
        }
        return maxSum;
    }
};
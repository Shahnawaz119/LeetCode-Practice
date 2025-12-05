class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;
        for(int i=0; i<n; i++){
            total_sum+=nums[i];
        }
        int currSum=0;
        int count=0;
        for(int i=0; i<n-1; i++){
            currSum+=nums[i];
            if(abs(currSum-abs(total_sum-currSum))%2==0){
                count++;
            }
        }
        return count;
    }
};
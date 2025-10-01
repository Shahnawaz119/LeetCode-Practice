class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int max_ones=0;
        int curr_ones=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                curr_ones=0;
            }else{
                curr_ones++;
            }
            max_ones=max(max_ones,curr_ones);
        }
        return max_ones;
    }
};
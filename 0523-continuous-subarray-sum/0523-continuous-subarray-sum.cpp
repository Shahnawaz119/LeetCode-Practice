class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0; i<nums.size(); i=i+2){
            sum=sum+nums[i]+nums[i+1];
            if(sum%k==0){
                return true;
            }
            
        }
        return false;
    }
};
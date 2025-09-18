class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        sort(nums.begin(),nums.end());
        int idx=0;
        for(int i=0; i<n; ){
            if(nums[i]==nums[i+1]){
                i+=2;
                idx=i;
            }else{
                break;
            }
        }
        return nums[idx];
    }
};
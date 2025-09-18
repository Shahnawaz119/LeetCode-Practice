class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int txor=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            txor=txor^nums[i];
        }
        unsigned int mask= txor & -txor;
        vector<int> ans(2,0);
        for(int i=0; i<n; i++){
            if((nums[i] & mask)==0){
                ans[0]^=nums[i];
            }else{
                ans[1]^=nums[i];
            }
        }
        return ans;
    }

};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        // sort(nums.begin(),nums.end());
        // int freq=1;
        // int ans=nums[0];
        // for(int i=1; i<n; i++){
        //     if(nums[i]==nums[i-1]){
        //         freq++;
        //     }else{
        //         freq=1;
        //         ans=nums[i];
        //     }
        //     if(freq>(n/2)){
        //         return ans;
        //     }
        // } 
        // return -1;
        int cond=nums[0];
        int count=0;
        for(int i=0; i<n; i++){
            if(count==0){
                cond=nums[i];
            }
            if(cond==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return cond;
    }
};
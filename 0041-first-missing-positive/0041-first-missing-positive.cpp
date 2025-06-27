class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // int n=nums.size();
        // for(int i=0; i<n; i++){
        //     if(nums[i]<=0 || nums[i]>=(n+1)){
        //         nums[i]=n+1;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     int element=abs(nums[i]);
        //     if(element>=1 && element<=n){
        //         if(nums[element-1]>0){
        //             nums[element-1]=-nums[element-1];
        //         }
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(nums[i]>0){
        //         return i+1;
        //     }
        // }
        int n=nums.size();
        for(int i=0; i<n; ){
            if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }else{
                i++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};
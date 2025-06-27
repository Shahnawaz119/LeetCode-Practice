class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size();
        // vector<bool> isPresent(n+1,false);
        // for(int i=0; i<n; i++){
        //     int idx=nums[i];
        //     isPresent[idx]=true;
        // }
        // for(int i=0; i<isPresent.size(); i++){
        //     if(isPresent[i]==false){
        //         return i;
        //     }
        // }
        // return -1;
        int n=nums.size();
        for(int i=0; i<n; ){
            if(nums[i]<n && nums[i]!=nums[nums[i]]){
                swap(nums[i],nums[nums[i]]);
            }else{
                i++;
            }
        }
        for(int i=0; i<n; i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return n;
    }
};
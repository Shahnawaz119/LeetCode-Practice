class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int rsum=0;
        for(int i=0; i<n; i++){
            rsum+=nums[i];
        }
        int lsum=0;
        for(int i=0; i<n; i++){
            rsum=rsum-nums[i];
            if(lsum==rsum){
                return i;
            }
            lsum+=nums[i];
        }
        
        return -1;
    }
};
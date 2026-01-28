class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum=0;
        int n=nums.size();
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
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int i;
        int countZero=0;
        for(i=0; i<n; i++){
            if(nums[i]>0){
                break;
            }
            if(nums[i]==0){
                countZero++;
            }
        }
        n=n-countZero;
        i=i-countZero;
        return max((n-i),i);
    }
};
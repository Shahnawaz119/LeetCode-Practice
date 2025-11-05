class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int pro=1;
        int left=0;
        for(int right=0; right<nums.size(); right++){
            pro*=nums[right];   
            while(pro>=k && left<=right){
                pro=pro/nums[left];
                left++;
            }
            count+=(right-left+1);
        }
        return count;
    }
};
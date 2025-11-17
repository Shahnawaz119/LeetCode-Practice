class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int left=-1;
        for(int right=0; right<nums.size(); right++){
            if(nums[right]==1){
                if(left!=-1 && (right-left-1)<k){
                    return false;
                }
                left=right;
            }
        }
        return true;
    }
};
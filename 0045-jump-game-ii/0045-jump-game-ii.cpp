class Solution {
public:
    int jump(vector<int>& nums) {
        int currMax=0;
        int currReach=0;
        int jump=0;
        for(int i=0; i<nums.size()-1; i++){
            if(i+nums[i]>currMax){
                currMax=i+nums[i];

            }
            if(currReach==i){
                jump++;
                currReach=currMax;
            }
        }
        return jump;
    }
};
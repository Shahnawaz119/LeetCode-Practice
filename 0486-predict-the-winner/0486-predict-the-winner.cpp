class Solution {
public:
    int solve(int i,int j,vector<int> &nums){
        if(i>j){
            return 0;
        }
        if(i==j){
            return nums[i];
        }
        int take_i=nums[i] + min(solve(i+2,j,nums),solve(i+1,j-1,nums));
        int take_j=nums[j] + min(solve(i,j-2,nums),solve(i+1,j-1,nums));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total_score=accumulate(nums.begin(),nums.end(),0);
        int players1_score=solve(0,n-1,nums);
        int players2_score=total_score-players1_score;
        return players1_score>=players2_score;
    }
};
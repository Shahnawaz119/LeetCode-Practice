class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int move=0;
        int Min=INT_MAX;

        for(int i=0; i<n; i++){
            if(Min>nums[i]){
                Min=min(Min,nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            move=move+(nums[i]-Min);
        }
        return move;
    }
};
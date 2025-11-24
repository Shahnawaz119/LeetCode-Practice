class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxDiv=0;
        int minValue=INT_MAX;
        for(int i=0; i<divisors.size(); i++){
            int currDiv=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j]%divisors[i]==0){
                    currDiv++;
                }
            }
            if(currDiv>maxDiv){
                maxDiv=currDiv;
                minValue=divisors[i];
            }else if(currDiv==maxDiv){
                minValue=min(minValue,divisors[i]);
            }
        }
        return minValue;
    }
};
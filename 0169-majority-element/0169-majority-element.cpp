class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int condidate=nums[0];
        int count=0;
        for(int i=0; i<n; i++){
            if(count==0){
                condidate=nums[i];
            }
            if(condidate==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        return condidate;
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size(); 
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]<3){
                count++;
            }else{
                int rem=nums[i]%3;
                count=count+min(rem,abs(3-rem));
            }
        }
        return count;
    }
};
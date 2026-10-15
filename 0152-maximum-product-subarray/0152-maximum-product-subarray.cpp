class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxPro=INT_MIN;
        
        for(int i=0; i<n; i++){
            int currPro=1;
            for(int j=i; j<n; j++){
                currPro*=nums[j];
                maxPro=max(maxPro,currPro);
            }
        }
        return maxPro;
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxLen=INT_MIN;
        for(int i=0; i<n; i++){
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;
            if(nums[i]%2==0){
                evenSet.insert(nums[i]);
            }else{
                oddSet.insert(nums[i]);
            }
            for(int j=i+1; j<n; j++){
                if(nums[j]%2==0){
                    evenSet.insert(nums[j]);
                }else{
                    oddSet.insert(nums[j]);
                }
                if(evenSet.size()==oddSet.size()){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen==INT_MIN?0:maxLen;
    }
};
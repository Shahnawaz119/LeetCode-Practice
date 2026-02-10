class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxLen=INT_MIN;
        for(int i=0; i<n; i++){
            unordered_set<int> seenEven,seenOdd;
            if(nums[i]%2==0){
                seenEven.insert(nums[i]);
            }else{
                seenOdd.insert(nums[i]);
            }
            for(int j=i+1; j<n; j++){
                if(nums[j]%2==0){
                    seenEven.insert(nums[j]);
                }else{
                    seenOdd.insert(nums[j]);
                }
                if(seenEven.size()==seenOdd.size()){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        return maxLen==INT_MIN?0:maxLen;
    }
};
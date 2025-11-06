class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x){
            return -1; 
        }
        int remainingSum=sum-x;
        sum=0;
        int longestSubArray=INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int findSum=sum-remainingSum;
            if(mp.find(findSum)!=mp.end()){
                longestSubArray=max(longestSubArray,i-mp[findSum]);
            }
        }
        return longestSubArray==INT_MIN?-1:(n-longestSubArray);
    }

};
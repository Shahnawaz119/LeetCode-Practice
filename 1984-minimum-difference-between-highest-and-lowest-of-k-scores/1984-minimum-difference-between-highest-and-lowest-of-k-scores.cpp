class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=k-1;
        while(j<n){
            int currDiff=nums[j]-nums[i];
            if(ans>currDiff){
                ans=currDiff;
            }
            j++;
            i++;
        }
        return ans;
    }
};
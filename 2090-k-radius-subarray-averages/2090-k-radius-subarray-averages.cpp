class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,-1);
        if(n<=2*k){
            return ans;
        }
        int left=0;
        int right=2*k;
        int i=k;
        int currSum=0;
        for(int z=0; z<=right; z++){
            currSum+=nums[z];
        }
        ans[i]=currSum/(2*k+1);
        right++;
        i++;
        while(right<n){
            currSum=currSum+nums[right]-nums[left];
            ans[i]=currSum/(2*k+1);
            left++;
            right++;
            i++;
        }
        return ans;
    }
};
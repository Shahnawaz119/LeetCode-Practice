class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int left=0;
        int right=0;
        while(right<n){
            while((long long)nums[right]>(long long)nums[left]*k){
                left++;
            }
            ans=min(ans,(n-(right-left+1)));
            right++;
        }
        return ans;

    }
};
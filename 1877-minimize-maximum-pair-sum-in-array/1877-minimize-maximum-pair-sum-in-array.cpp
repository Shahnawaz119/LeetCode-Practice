class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            int sum=nums[i]+nums[n-1-i];
            ans.push_back(sum);
        }
        int result=INT_MIN;
        for(auto x:ans){
            if(x>result){
                result=x;
            }
        }
        return result;
    }
};
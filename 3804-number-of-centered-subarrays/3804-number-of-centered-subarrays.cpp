class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int currSum=0;
            unordered_set<int> st;
            for(int j=i; j<n; j++){
                st.insert(nums[j]);
                currSum+=nums[j];
                if(st.find(currSum)!=st.end()){
                    ans++;
                }
            }
        }
        return ans;
    }
};
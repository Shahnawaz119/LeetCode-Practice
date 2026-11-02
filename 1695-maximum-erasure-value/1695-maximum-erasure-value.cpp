class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int sum=0;
        int maxSum=0;
        unordered_set<int> st;
        while(right<n){
            int ele=nums[right];
            if(st.find(ele)==st.end()){
                st.insert(ele);
                sum+=ele;
                maxSum=max(maxSum,sum);
                right++;
            }else{
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
        }
        return maxSum;
    }
};
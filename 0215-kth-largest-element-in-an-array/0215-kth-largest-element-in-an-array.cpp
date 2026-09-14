class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int>q(nums.begin(),nums.end());
        while(!q.empty() && k>1){
            q.pop();
            k--;
        }
        return q.top();
    }
};
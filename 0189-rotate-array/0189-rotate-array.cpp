class Solution {
public:
    void Reverse(vector<int>&nums,int i,int j){
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==k || k==0){
            return;
        }
        if(k>n){
            k=k%n;
        }
        Reverse(nums,n-k,n-1);
        Reverse(nums,0,n-k-1);
        Reverse(nums,0,n-1);
    }
};
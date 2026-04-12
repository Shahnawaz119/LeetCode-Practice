class Solution {
public:
    long long merge(vector<int>&nums,int st,int mid,int end){
        long long count=0;
        int i=st;
        int j=mid+1;
        for(int i=st; i<=mid; i++){
            while(j<=end && nums[i] > 2LL *nums[j]){
                j++;
            }
            count+=(j-(mid+1));
        }
        j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=end){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(j<=end){
            temp.push_back(nums[j]);
            j++;
        }
        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        for(int k=0; k<temp.size(); k++){
            nums[k+st]=temp[k];
        }
        return count;
    }
    long long solve(vector<int> &nums,int st,int end){
        if(st<end){
            int mid=st+(end-st)/2;
            long long left=solve(nums,st,mid);
            long long right=solve(nums,mid+1,end);
            long long curr=merge(nums,st,mid,end);
            return curr+left+right;
        }
        return 0;
    }
    int reversePairs(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};
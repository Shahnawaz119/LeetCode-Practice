class Solution {
public:
    bool possible(vector<int> &nums,int maxOpe,long long mid){
        long long totalOpe=0;
        for(int num:nums){
            int ops=num/mid;
            if(num%mid==0){
                ops-=1;
            }
            totalOpe+=ops;
        }
        return totalOpe<=maxOpe;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        long l=1;
        long r= *max_element(nums.begin(),nums.end());
        long result=r;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(possible(nums,maxOperations,mid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};
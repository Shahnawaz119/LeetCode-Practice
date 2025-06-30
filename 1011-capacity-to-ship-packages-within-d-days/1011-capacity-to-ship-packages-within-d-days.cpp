class Solution {
public:
    bool helper(vector<int> &weights,int mid,int days){
        int currDay=1;
        int currWeight=0;
        for(int weight:weights){
            if(weight+currWeight>mid){
                currDay++;
                currWeight=0;
            }
            currWeight+=weight;
        }
        if(days>=currDay){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=INT_MIN;
        int right=0;
        for(int i=0; i<weights.size(); i++){
            left=max(left,weights[i]);
            right+=right+weights[i];
        }
        long ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(helper(weights,mid,days)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
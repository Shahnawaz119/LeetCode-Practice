class Solution {
public:
    bool helper(vector<int>& piles,int mid,int h){
        int hours=0;
        for(int i=0; i<piles.size(); i++){
            hours+=(long)(piles[i]+mid-1)/(long)mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long left=1;
        long right=1e9;
        long ans=0;
        while(left<=right){
            long mid=left+(right-left)/2;
            if(helper(piles,mid,h)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
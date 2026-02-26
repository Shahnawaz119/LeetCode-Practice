class Solution {
public:
    bool helper(vector<int>&piles,long long mid,int h){
        long long hours=0;
        for(int i=0; i<piles.size(); i++){
            hours+=(long)(piles[i]+mid-1)/mid;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left=1;
        long long right=1e9;
        long long ans=0;
        while(left<=right){
            long long mid=left+(right-left)/2;
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
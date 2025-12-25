class Solution {
public:
    bool canDistribute(vector<int> &candies,long long mid,long long k){
        long long count=0;
        for(int i=0; i<candies.size(); i++){
            count+=candies[i]/mid;
            if(count>=k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long maxC=0;
        long long total=0;
        for(int i=0; i<n; i++){
            total+=candies[i];
            maxC=max(maxC,(long long)candies[i]);
        }
        if(total<k){
            return 0;
        }
        int l=1; 
        int r=maxC;
        int result=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(canDistribute(candies,mid,k)){
                result=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
};
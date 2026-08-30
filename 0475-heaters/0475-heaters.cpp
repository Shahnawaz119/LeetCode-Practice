class Solution {
public:
    int n,m;
    bool possible(int mid,vector<int>&houses,vector<int>&heaters){
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(abs(houses[i]-heaters[j])<=mid){
                i++;
            }else{
                j++;
            }
            if(j==m){
                return false;
            }
        }
        return i==n;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        n=houses.size();
        m=heaters.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int left=0;
        int right=1e9;
        int ans=-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(possible(mid,houses,heaters)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
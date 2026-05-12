class Solution {
public:
    bool isPossible(vector<int>&quantities,int mid,int n){
        int count=0;
        for(int i=0; i<quantities.size(); i++){
            count+=(quantities[i]+mid-1)/mid;
            if(count>n){
                return false;
            }
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int m=quantities.size();
        int left=1;
        int right=INT_MIN;
        int ans=-1;
        for(int i=0; i<m; i++){
            if(right<quantities[i]){
                right=quantities[i];
            }
        }
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isPossible(quantities,mid,n)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};
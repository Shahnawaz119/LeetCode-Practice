class Solution {
public:
    int mySqrt(int x) {
        if(x==1 || x==0){
            return x;
        }
        int ans=0;
        int i=0;
        int j=x-1;
        while(i<=j){
            long mid=i+(j-i)/2;
            if(mid*mid<=x){
                ans=mid;
                i=mid+1;
            }else if(mid*mid>x){
                j=mid-1;
            }
        }
        return ans;
    }
};
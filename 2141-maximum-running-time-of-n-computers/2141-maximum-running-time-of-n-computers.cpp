class Solution {
public:
    bool possible(vector<int> &batteries,long long mid_minute,int n){
        long long target_minute=n*mid_minute;
        long long sum=0;
        for(int i=0; i<batteries.size(); i++){
            sum+=min((long long)batteries[i],mid_minute);
            if(sum>=target_minute){
                return true;
            }
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=*min_element(batteries.begin(),batteries.end());
        long long sum_total_minutes=0;
        for(auto &min:batteries){
            sum_total_minutes+=min;
        }
        long long r=sum_total_minutes/n;
        long long result=0;
        while(l<=r){
            long long mid_minute=l+(r-l)/2;
            if(possible(batteries,mid_minute,n)){
                result=mid_minute;
                l=mid_minute+1;
            }else{
                r=mid_minute-1;
            }
        }
        return result;
    }
};
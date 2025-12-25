class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        int count=0;
        long long sum=0;
        sort(happiness.rbegin(),happiness.rend());
        if(k==0){
            return 0;
        }
        if(k==1){
            return happiness[0];
        }
        sum+=happiness[0];
        count++;
        for(int i=1; i<n; i++){
            if(count==k){
                break;
            }
            if(happiness[i]-i<0){
                count++;
                continue;
            }else{
                sum+=(happiness[i]-i);
                count++;
            }
        }
        return sum;
    }
};
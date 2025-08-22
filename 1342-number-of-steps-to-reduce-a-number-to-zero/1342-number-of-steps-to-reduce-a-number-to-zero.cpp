class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0){
            return 0;
        }
        if(num==1){
            return 1;
        }
        if(num==2){
            return 2;
        }
        vector<int> dp(num+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=num; i++){
            dp[i]=1+min(dp[i-1],(i%2==0)? dp[i/2]:INT_MAX);
        }
        return dp[num];

    }
};
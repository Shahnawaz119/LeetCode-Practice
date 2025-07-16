class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1){
            return false;
        }
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;

        vector<vector<long long>> arr(n+1,vector<long long> (target+1,0));
        arr[0][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(nums[i-1]>j){
                    arr[i][j]=arr[i-1][j];
                }else{
                    arr[i][j]=arr[i-1][j]+arr[i-1][j-nums[i-1]];
                }
            }
        }
        return arr[n][target]>0;
    }
};
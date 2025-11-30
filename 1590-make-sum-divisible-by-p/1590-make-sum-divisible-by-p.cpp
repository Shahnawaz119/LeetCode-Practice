class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum=(sum+nums[i])%p;
        }
        int target=sum%p;
        if(target==0){
            return 0;
        }
        unordered_map<int,int> mp;
        int curr=0;
        mp[0]=-1;
        int result=INT_MAX;
        for(int i=0; i<n; i++){
            curr=(curr+nums[i])%p;
            int remain=(curr-target+p)%p;
            if(mp.find(remain)!=mp.end()){
                if((i-mp[remain])<n){
                    result=min(result,i-mp[remain]);
                }
            }
            mp[curr]=i;
        }
        return result==INT_MAX?-1:result;
    }
};
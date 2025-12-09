class Solution {
public:
    const long long MOD=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> left,right;
        int count=0;
        for(int i=0; i<n; i++){
            right[nums[i]]++;
        }
        long long ans=0;
        for(int j=0; j<n; j++){
            int mid=nums[j];
            int target=mid*2;
            right[mid]--;

            int leftCount=left[target];
            int rightCount=right[target];

            ans=(ans+(leftCount*rightCount)%MOD)%MOD;
            left[mid]++;
        }
        return ans;
    }
};
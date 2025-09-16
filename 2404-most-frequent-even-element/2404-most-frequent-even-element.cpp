class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                m[nums[i]]++;
            }
        }
        int freq=0;
        int ans=-1;
        for(auto x:m){
            if(x.second>freq || (x.second==freq && x.first<ans)){
                ans=x.first;
                freq=x.second;
            }
        }
        return ans;
    }
};
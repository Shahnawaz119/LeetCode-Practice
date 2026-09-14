class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return -1;
        }
        unordered_map<int,int> map;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                map[nums[i]]++;
            }
        }
        int freq=0;
        int ans=-1;
        for(auto it=map.begin(); it!=map.end(); it++){
            int key=it->first;
            int value=it->second;
            if(freq<value || (freq==value && key<ans)){
                ans=key;
                freq=value;
            }
        }
        return ans;
    }
};
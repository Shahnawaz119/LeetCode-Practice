class Solution {
public:
    void findDuplicate(vector<int> &arr,unordered_map<int,int> &mp){
        unordered_map<int,int> mp1;
        for(int i=0; i<arr.size(); i++){
            mp1[arr[i]]++;
        }
        for(auto it=mp.begin(); it!=mp.end();){
            if(mp1.find(it->first)!=mp1.end()){
                it->second=min(it->second,mp1[it->first]);
                it++;
            }else{
                it=mp.erase(it);
            }
        }
    }
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums[0].size(); i++){
            mp[nums[0][i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            findDuplicate(nums[i],mp);
        }
        vector<int> ans;
        for(auto it:mp){
            for(int i=0; i<it.second; i++){
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
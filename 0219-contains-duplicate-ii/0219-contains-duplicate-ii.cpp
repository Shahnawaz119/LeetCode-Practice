class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size()==1){
            return false;
        }
        unordered_map<int,int> map;
        for(int i=0; i<nums.size(); i++){
            map[nums[i]]++;
        }
        vector<int> idx;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]]==1){
                idx.push_back(i);
            }
        }
        if(idx.size()==1){
            return true;
        }
        if(idx.size()==2 && abs(idx[0]-idx[1])<=k){
            return true;
        }
        return false;
    }
};
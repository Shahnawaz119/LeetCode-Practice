class Solution {
public:
    set<vector<int>> s;
    void allUniquePair(vector<int>&nums,vector<vector<int>>&ans,int idx){
        if(idx==nums.size()){
            if(s.find(nums)==s.end()){
                ans.push_back(nums);
                s.insert(nums);
                
            }
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx],nums[i]);
            allUniquePair(nums,ans,idx+1);
            swap(nums[idx],nums[i]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        allUniquePair(nums,ans,0);
        return ans;

    }
};
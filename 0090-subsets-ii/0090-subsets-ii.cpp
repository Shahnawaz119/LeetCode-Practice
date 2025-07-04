class Solution {
public:
    set<vector<int>>s;
    void subset(vector<int> &nums,vector<int> temp,vector<vector<int>> &ans ,int idx){
        if(s.find(temp)==s.end()){
            ans.push_back(temp);
            s.insert(temp);
        }
        for(int i=idx; i<nums.size(); i++){
            temp.push_back(nums[i]);
            subset(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        subset(nums,temp,ans,0);
        return ans;
    }
};
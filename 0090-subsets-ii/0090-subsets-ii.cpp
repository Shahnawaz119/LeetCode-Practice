class Solution {
public:
    void solve(vector<int>&arr,vector<int>&temp,vector<vector<int>>&ans,int idx){
        ans.push_back(temp);
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            temp.push_back(arr[i]);
            solve(arr,temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,ans,0);
        return ans;
    }
};
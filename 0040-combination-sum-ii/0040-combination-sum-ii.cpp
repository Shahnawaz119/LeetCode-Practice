class Solution {
public:
    void solve(vector<int> &arr,int tar,vector<int>&curr,int idx,vector<vector<int>>&ans){
        if(tar<0){
            return;
        }
        if(tar==0){
            ans.push_back(curr);
        }
        for(int i=idx; i<arr.size(); i++){
            if(i>idx && arr[i]==arr[i-1]){
                continue;
            }
            curr.push_back(arr[i]);
            solve(arr,tar-arr[i],curr,i+1,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(arr.begin(),arr.end());
        solve(arr,tar,curr,0,ans);
        return ans;
    }
};
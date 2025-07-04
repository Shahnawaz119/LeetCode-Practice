class Solution {
public:
    set<vector<int>> s;
    void getAllCombination(vector<int>&arr,int tar,int idx,vector<int>&combi,vector<vector<int>>&ans){
        if(idx==arr.size() || tar<0){
            return;
        }
        if(tar==0){
            if(s.find(combi)==s.end()){
                ans.push_back(combi);
                s.insert(combi);
            }
            return;
        }
        combi.push_back(arr[idx]);
        getAllCombination(arr,tar-arr[idx],idx+1,combi,ans);
        getAllCombination(arr,tar-arr[idx],idx,combi,ans);
        combi.pop_back();
        getAllCombination(arr,tar,idx+1,combi,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combi;
        getAllCombination(arr,tar,0,combi,ans);
        return ans;
    }
};
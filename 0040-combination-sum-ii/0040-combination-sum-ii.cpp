class Solution {
public:
    void solve(vector<int> &candi,vector<int>&temp,vector<vector<int>>&ans,int tar,int idx){
        if(tar<0){
            return;
        }
        if(tar==0){
            ans.push_back(temp);
            return;
        }
        for(int i=idx; i<candi.size(); i++){
            if(i>idx && candi[i]==candi[i-1]){
                continue;
            }
            temp.push_back(candi[i]);
            solve(candi,temp,ans,tar-candi[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,temp,ans,target,0);
        return ans;
    }
};
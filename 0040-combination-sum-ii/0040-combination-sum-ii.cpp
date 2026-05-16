class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>&candi,int idx,vector<int>&temp,int tar){
        if(tar<0){
            return;
        }
        if(tar==0){
            ans.push_back(temp); 
        }
        for(int i=idx; i<candi.size(); i++){
            if(i>idx && candi[i]==candi[i-1]){
                continue;
            }
            temp.push_back(candi[i]);
            solve(candi,i+1,temp,tar-candi[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,temp,target);
        return ans;
    }
};
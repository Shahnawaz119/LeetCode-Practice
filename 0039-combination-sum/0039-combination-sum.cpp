class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>>s;
    void solve(vector<int>&candi,int idx,int tar,vector<int>&temp){
        if(tar<0 || idx==candi.size()){
            return;
        }
        if(tar==0){
            if(s.find(temp)==s.end()){
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }
        temp.push_back(candi[idx]);
        solve(candi,idx,tar-candi[idx],temp);
        temp.pop_back();
        solve(candi,idx+1,tar,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,0,target,temp);
        return ans;
    }
};
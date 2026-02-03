class Solution {
public:
    set<vector<int>> s;
    void findCombination(vector<int>&candi,int tar,vector<int>&temp,vector<vector<int>>&ans,int idx){
        if(tar<0 || idx==candi.size()){
            return;
        }
        if(tar==0){
            if(s.find(temp)==s.end()){
                ans.push_back(temp);
                s.insert(temp);
            }
            return ;
        }
        temp.push_back(candi[idx]);
        findCombination(candi,tar-candi[idx],temp,ans,idx);
        temp.pop_back();
        findCombination(candi,tar,temp,ans,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        findCombination(candidates,target,temp,ans,0);
        return ans;
    }
};
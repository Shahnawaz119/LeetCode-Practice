class Solution {
public:
    set<vector<int>> st;
    void combinations(vector<int>&candi,int target,vector<vector<int>>&ans,vector<int>&temp,int idx){
        if(target<0 || idx==candi.size()){
            return;
        }
        if(target==0){
            if(st.find(temp)==st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            return;
        }
        temp.push_back(candi[idx]);
        combinations(candi,target-candi[idx],ans,temp,idx);
        temp.pop_back();
        combinations(candi,target,ans,temp,idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates,target,ans,temp,0);
        return ans;
    }
};
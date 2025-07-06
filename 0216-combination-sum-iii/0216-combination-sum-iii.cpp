class Solution {
public:
    void solve(int k,int n,vector<int>&temp,vector<vector<int>>&ans,int start){
        if(k==0 && n==0){
            ans.push_back(temp);
            return;
        }
        if(start>9 || k==0 || n<0){
            return;
        }
        temp.push_back(start);
        solve(k-1,n-start,temp,ans,start+1); //current include number
        temp.pop_back();
        solve(k,n,temp,ans,start+1); // backtrack and exclude current
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> temp;
        solve(k,n,temp,ans,1);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int> &nums,vector<int> &temp,int idx){
        if(idx==nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        solve(nums,temp,idx+1);
        temp.pop_back();
        solve(nums,temp,idx+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> temp;
      solve(nums,temp,0);
      return result;  
    }
};
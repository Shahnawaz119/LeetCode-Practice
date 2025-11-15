class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            string num=to_string(nums[i]);
            for(int j=0; j<num.length(); j++){
                ans.push_back(num[j]-'0');
            }
        }
        return ans;
    }
};
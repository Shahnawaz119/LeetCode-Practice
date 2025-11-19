class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for(auto it=s.begin(); it!=s.end(); it++){
            if(s.count(original)){
                original=original*2;
            }
        }
        return original;
    }
};
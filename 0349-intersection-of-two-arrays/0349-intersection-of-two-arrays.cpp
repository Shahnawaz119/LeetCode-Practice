class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        for(auto x:nums1){
            s1.insert(x);
        }
        vector<int> ans;
        for(auto x:nums2){
            if(s1.find(x)!=s1.end()){
                ans.push_back(x);
                s1.erase(x);
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        for(int el:nums2){
            s.insert(el);
        }
        for(int el:nums1){
            if(s.find(el)!=s.end()){
                ans.push_back(el);
            }
        }
        return ans;
    }
};
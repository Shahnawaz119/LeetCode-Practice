class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> s;
        for(int el:nums1){
            s.insert(el);
        }
        unordered_set<int> s1;
        for(int el:nums2){
            if(s.find(el)!=s.end()){
                s1.insert(el);
            }
        }
        for(int el:s1){
            ans.push_back(el);
        }
        return ans;
        
    }
};
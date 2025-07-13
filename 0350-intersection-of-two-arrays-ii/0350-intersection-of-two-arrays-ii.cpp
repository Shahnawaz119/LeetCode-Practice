class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            freq[nums2[i]]++;
        }
        for(int i=0; i<nums1.size(); i++){
            if(freq.count(nums1[i])){
                ans.push_back(nums1[i]);
                freq[nums1[i]]--;
                if(freq[nums1[i]]==0){
                    freq.erase(nums1[i]);
                }
            }
        }
        return ans;
    }
};
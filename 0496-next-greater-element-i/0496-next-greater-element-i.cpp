class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> st;
        for(int i=nums2.size()-1; i>=0; i--){
            int curr=nums2[i];
            while(!st.empty() && curr>=st.top()){
                st.pop();
            }
            if(st.empty()){
                map[nums2[i]]=-1;
            }else{
                map[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            if(map.find(nums1[i])!=map.end()){
                ans.push_back(map[nums1[i]]);
            }
        }
        return ans;
    }
};
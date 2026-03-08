class Solution {
public:
    int n;
    unordered_set<string> st;
    void solve(string temp){
        if(temp.length()==n){
            st.insert(temp);
            return;
        }
        solve(temp+"0");
        solve(temp+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        n=nums.size();
        solve("");
        for(int i=0; i<n; i++){
            if(st.find(nums[i])!=st.end()){
                st.erase(nums[i]);
            }
        }
        return *st.begin();
    }

};
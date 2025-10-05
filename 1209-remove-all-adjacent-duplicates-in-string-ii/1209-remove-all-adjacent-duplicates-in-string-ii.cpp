class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        stack<pair<char,int>> st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(!st.empty() && st.top().first==ch){
                st.top().second++;
                if(st.top().second==k){
                    st.pop();
                }
                continue;
            }
            st.push({ch,1});
        }
        string ans="";
        while(!st.empty()){
            ans.append(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
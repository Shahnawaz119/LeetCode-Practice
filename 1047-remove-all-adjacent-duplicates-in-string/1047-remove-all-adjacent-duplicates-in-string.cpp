class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(!st.empty() && ch==st.top()){
                while(!st.empty() && ch==st.top()){
                    st.pop();
                }
                continue;
            }
            st.push(ch);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n%2!=0){
            return 0;
        }
        stack<char> st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char top=st.top();
                    if((top=='(' && ch==')') || (top=='{' && ch=='}') || (top=='[' && ch==']')){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        return st.empty();
    }
};
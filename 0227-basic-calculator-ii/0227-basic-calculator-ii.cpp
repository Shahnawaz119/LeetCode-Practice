class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        int number=0;
        char op='+';
        stack<int> st;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(isdigit(ch)){
                number=number*10+(ch-'0');
            }
            if((!isdigit(ch) && ch!=' ') || i==n-1){
                if(op=='+'){
                    st.push(number);
                }else if(op=='-'){
                    st.push(-number);
                }else if(op=='/'){
                    int top=st.top();
                    st.pop();
                    st.push(top/number);
                }else if(op=='*'){
                    int top=st.top();
                    st.pop();
                    st.push(top*number);
                }
                number=0;
                op=ch;
            }
            
        }
        int result=0;
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        return result;
    }
};
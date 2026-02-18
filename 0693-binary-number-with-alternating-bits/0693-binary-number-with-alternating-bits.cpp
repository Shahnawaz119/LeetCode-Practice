class Solution {
public:
    bool hasAlternatingBits(int n) {
        stack<int> st;
        while(n>0){
            int bit=n&1;
            if(!st.empty() && st.top()==bit){
                return false;
            }
            st.push(bit);
            n=n>>1;
        }
        return true;
    }
};
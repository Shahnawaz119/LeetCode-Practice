class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen=0;
        int right=0;
        for(int i=0; i<s.length(); i++){
            unordered_set<char> st;
            int count=0;
            if(st.find(s[i])==st.end()){
                while(i<s.length() && st.find(s[i])==st.end()){
                    count++;
                    st.insert(s[i]);
                    i++;
                }
                maxLen=max(maxLen,count);
                i--;
            }
        }
        return maxLen;
    }
};
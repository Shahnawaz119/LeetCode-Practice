class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int right=0,left=0,maxLen=0;
        while(right<s.length()){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
                right++;
            }else{
                st.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
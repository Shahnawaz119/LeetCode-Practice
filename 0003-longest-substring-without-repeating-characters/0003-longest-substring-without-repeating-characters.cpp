class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_set<char> st;
        while(right<n){
            char ch=s[right];
            if(st.find(ch)==st.end()){
                st.insert(ch);
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
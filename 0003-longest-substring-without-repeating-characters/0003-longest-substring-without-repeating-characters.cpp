class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left=0;
        int right=0;
        int maxLen=0;
        int n=s.length();
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
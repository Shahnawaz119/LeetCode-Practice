class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int left=0;
        int right=0;
        int maxLength=0;
        while(right<s.length()){
            char ch=s[right];
            if(m.find(ch)!=m.end() && m[ch]>=left){
                left=m[ch]+1;
            }
            m[ch]=right;
            maxLength=max(maxLength,right-left+1);
            right++;
        }
        return maxLength;
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> latters;
        for(int i=0; i<s.length(); i++){
            latters.insert(s[i]);
        }
        int result=0;
        for(auto latter:latters){
            int left=-1;
            int right=-1;
            for(int i=0; i<s.length(); i++){
                if(s[i]==latter){
                    if(left==-1){
                        left=i;
                    }
                    right=i;
                }
            }
            unordered_set<char> st;
            for(int middle=left+1; middle<=right-1; middle++){
                st.insert(s[middle]);
            }
            result+=st.size();
        }
        return result;
    }
};
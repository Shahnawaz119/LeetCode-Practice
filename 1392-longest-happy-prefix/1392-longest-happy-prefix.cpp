class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> lps(n,0);
        int pre=0;
        int suf=1;
        while(suf<n){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                suf++;
                pre++;
            }else{
                if(pre==0){
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
        int strLen=lps[n-1];
        string ans="";
        for(int i=0; i<strLen; i++){
            ans+=s[i];
        }
        return ans;
    }
};
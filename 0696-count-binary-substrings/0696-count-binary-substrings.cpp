class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int count=1;
        int prev=0;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                count++;
            }else{
                ans+=min(prev,count);
                prev=count;
                count=1;
            }
        }
        ans+=min(prev,count);
        return ans;
    }
};
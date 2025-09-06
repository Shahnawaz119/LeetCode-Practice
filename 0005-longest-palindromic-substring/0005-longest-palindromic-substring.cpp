class Solution {
public:
    bool solve(string &s,int i,int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxLength=INT_MIN;
        int sp=0;
        int n=s.length();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s,i,j)){
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLength);
    }
};
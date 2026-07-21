class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        int i=0;
        while(i<n){
            int j=i;
            if(s[i]!=' '){
                while(j<n && s[j]!=' '){
                    j++;
                }
                reverse(s.begin()+i,s.begin()+j);
                i=j;
            }
            i++;
        }
        return s;
    }
};
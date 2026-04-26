class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(m<n){
            return false;
        }
        sort(s1.begin(),s1.end());
        for(int i=0; i<=m-n; i++){
            string newStr=s2.substr(i,n);
            sort(newStr.begin(),newStr.end());
            if(newStr==s1){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool goodSubStr(const string &str){
        return str[0]!=str[1] && str[0]!=str[2] && str[1]!=str[2];
    }
    int countGoodSubstrings(string s) {
        int n=s.length();
        if(n<3){
            return 0;
        }
        int count=0;
        for(int i=0; i<=n-3; i++){
            if(goodSubStr(s.substr(i,3))){
                count++;
            }
        }
        return count;
    }
};
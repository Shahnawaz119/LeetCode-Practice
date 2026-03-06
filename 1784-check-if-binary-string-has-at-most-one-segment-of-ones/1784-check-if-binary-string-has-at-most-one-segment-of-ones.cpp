class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int countOne=0;
        int countZero=0;
        for(int i=0; i<n; i++){
            if((countOne!=0 &&countZero!=0) && s[i]=='1'){
                return false;
            }
            if(s[i]=='1'){
                countOne++;
            }else{
                countZero++;
            }
        }
        return true;
    }
};
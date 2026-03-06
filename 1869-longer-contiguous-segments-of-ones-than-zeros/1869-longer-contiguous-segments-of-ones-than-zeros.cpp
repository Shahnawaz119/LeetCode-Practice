class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxZero=0, maxOne=0;
        int currZero=0,currOne=0;

        int n=s.length();
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                currOne++;
                currZero=0;
            }else{
                currZero++;
                currOne=0;
            }
            maxOne=max(maxOne,currOne);
            maxZero=max(maxZero,currZero);
        }
        return maxOne>maxZero;
    }
};
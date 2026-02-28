class Solution {
public:
    long const MOD=1e9+7;
    int concatenatedBinary(int n) {
        long result=0;
        int bits=0;
        for(int num=1; num<=n; num++){
            if((num&(num-1))==0){
                bits++;
            }
            result=((result<<bits)%MOD+num)%MOD;
        }
        return result;
    }
};
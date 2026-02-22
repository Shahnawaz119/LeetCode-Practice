class Solution {
public:
    int binaryGap(int n) {
        if(n==1){
            return 0;
        }
        int maxGap=0;
        int countZero=0;
        int countOne=0;
        while(n>0){
            int currBit=(n&1);
            if(currBit==0){
                countZero++;
            }else{
                countOne++;
                if(countOne<2){
                    countZero=0;
                }else{
                    maxGap=max(maxGap,countZero+1);
                    countZero=0;
                }
            }
            n=n>>1;
        }
        return maxGap;
    }
};
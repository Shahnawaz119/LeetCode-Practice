class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        while(n>0){
            if(i<=n){
                n=n-i;
                i++;
            }else{
                break;
            }
        }
        i--;
        return i;
    }
};
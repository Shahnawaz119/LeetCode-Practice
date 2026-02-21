class Solution {
public:
    int helper(int n){
        int count=0;
        while(n>0){
            int currBit=(n&1);
            if(currBit==1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left; i<=right; i++){
            if((i&(i-1))==0){
                continue;
            }
            int setBit=helper(i);
            if(isPrime(setBit)){
                ans++;
            }
        }
        return ans;
    }
};
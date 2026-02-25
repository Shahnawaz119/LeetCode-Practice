class Solution {
public:
    int findBit(int n){
        if((n&(n-1))==0){
            return 1;
        }
        int countBit=0;
        while(n>0){
            countBit+=(n&1);
            n>>=1;
        }
        return countBit;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[this](int a,int b){
            int countBitA=findBit(a);
            int countBitB=findBit(b);
            if(countBitA==countBitB){
                return a<b;
            }
            return countBitA<countBitB;
        });
        return arr;
    }
};
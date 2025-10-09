class Solution {
public:
    int getDigit(int n){
        int totalSum=0;
        while(n>0){
            totalSum+=(n%10)*(n%10);
            n/=10;
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n=getDigit(n);
        }
        return n==1;
    }
};
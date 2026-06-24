class Solution {
public:
    int getNum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            n=getNum(n);
        }
        return n==1;
    }
};
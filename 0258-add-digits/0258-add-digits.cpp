class Solution {
public:
    int getSum(int num){
        int totalSum=0;
        while(num>0){
            totalSum=totalSum+num%10;
            num/=10;
        }
        return totalSum;
    }
    int addDigits(int num) {
        if(num<10){
            return num;
        }
        unordered_set<int> s;
        while(num>=10 && s.find(num)==s.end()){
            s.insert(num);
            num=getSum(num);
        }
        return num;
    }
};
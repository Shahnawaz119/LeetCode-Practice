class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if((num-3)%3==0){
            long long x=(num-3)/3;
            ans={x,x+1,x+2};
        }
        return ans;
    }
};
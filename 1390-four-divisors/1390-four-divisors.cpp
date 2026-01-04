class Solution {
public:
    int solve(int num){
        int divisor=0;
        int sum=0;
        for(int fact=1; fact*fact<=num; fact++){
            if(num%fact==0){
                int other=num/fact;
                if(fact==other){
                    divisor++;
                    sum+=fact;
                }else{
                    divisor+=2;
                    sum+=fact+other;
                }
            }
            if(divisor>4){
                break;
            }
        }
        if(divisor==4){
            return sum;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int result=0;
        for(auto &num:nums){
            result+=solve(num);
        }
        return result;
    }
};
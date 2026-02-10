class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0;
        long long right=c;
        while(left<=right){
            long long val=left*left+right*right;
            if(val==c){
                return true;
            }else if(val>c){
                right--;
            }else{
                left++;
            }
        }
        return false;
    }
};
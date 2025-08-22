class Solution {
public:
    int f(int target,int maxD){
        if(target==1) return 0;
        if(maxD==0) return target-1;
        if(target%2==0){
            return 1+f(target/2,maxD-1);
        }else{
            return 1+f(target-1,maxD);
        }
    }
    int minMoves(int target, int maxDoubles) {
        return f(target,maxDoubles);
    }
};
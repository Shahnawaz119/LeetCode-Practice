class Solution {
public:
    int const M=1e9+7;
    int t[201][201][2];
    int solve(int leftOne,int leftZero,bool lastWasOne,int limit){
        if(leftOne==0 && leftZero==0){
            return 1;
        }
        if(t[leftOne][leftZero][lastWasOne]!=-1){
            return t[leftOne][leftZero][lastWasOne];
        }
        int result=0;
        
        if(lastWasOne==true){
            for(int len=1; len<=min(leftZero,limit); len++){
                result=(result+solve(leftOne,leftZero-len,false,limit))%M;
            }
        }else{
            for(int len=1; len<=min(leftOne,limit); len++){
                result=(result+solve(leftOne-len,leftZero,true,limit))%M;
            }
        }
        return t[leftOne][leftZero][lastWasOne]=result;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t,-1,sizeof(t));
        int startWithZero=solve(one,zero,false,limit);
        int startWithOne=solve(one,zero,true,limit);
        return (startWithZero+startWithOne)%M;
    }
};
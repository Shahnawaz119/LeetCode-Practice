class Solution {
public:
    const int m=1000000007;
    int numSub(string s) {
        int n=s.length();
        long long countOnes=0;
        long long result=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                countOnes++;
            }else{
                result=(result+(countOnes*(countOnes+1)/2)%m)%m;
                countOnes=0;
            }
        }
        result=(result+(countOnes*(countOnes+1)/2)%m)%m;
        return (int)result;
    }
};
class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return n=0;
        }
        if(n==1 || n==2){
            return 1;
        }
        vector<int> arr(n+1);
        arr[0]=0;
        arr[1]=1;
        arr[2]=1;
        for(int i=3; i<=n; i++){
            arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
        }
        return arr[n];
    }
};
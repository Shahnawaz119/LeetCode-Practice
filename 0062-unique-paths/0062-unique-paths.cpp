class Solution {
public:
    int helper(int i,int j,int m,int n){
        if(i>m || j>n){
            return 0;
        }
        if(i==m && j==n){
            return 1;
        }
        int rightWay=helper(i,j+1,m,n);
        int downWay=helper(i+1,j,m,n);
        return rightWay+downWay;

    }
    int uniquePaths(int m, int n) {
        return helper(0,0,m-1,n-1);
    }
};
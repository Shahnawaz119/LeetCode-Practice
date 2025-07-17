class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int n=s.size()+1;
        vector<vector<int>> arr(n,vector<int> (n,0));
        for(int i=1; i<n; i++){
            for(int j=1; j<n; j++){
                if(s[i-1]==s1[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n-1][n-1];
    }
};
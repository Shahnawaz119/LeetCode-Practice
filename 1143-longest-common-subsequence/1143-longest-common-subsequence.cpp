class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size()+1;
        int m=text2.size()+1;
        vector<vector<int>> arr(n,vector<int> (m,0));
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(text1[i-1]==text2[j-1]){
                    arr[i][j]=arr[i-1][j-1]+1;
                }else{
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }
            }
        }
        return arr[n-1][m-1];
    }
};
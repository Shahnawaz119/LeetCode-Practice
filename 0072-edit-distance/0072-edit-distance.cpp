class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size()+1;
        int m=word2.size()+1;
        vector<vector<int>> arr(n,vector<int> (m,0));
        for(int i=0; i<n; i++){
            arr[i][0]=i;
        }
        for(int j=0; j<m; j++){
            arr[0][j]=j;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(word1[i-1]==word2[j-1]){
                    arr[i][j]=arr[i-1][j-1];
                }else{
                    arr[i][j]=min(arr[i-1][j-1],min(arr[i-1][j],arr[i][j-1]))+1;
                }
            }
        }
        return arr[n-1][m-1];
    }
};
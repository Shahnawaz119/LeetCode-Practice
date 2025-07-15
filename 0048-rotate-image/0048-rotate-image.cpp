class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int temp=mat[i][j];
                mat[i][j]=mat[j][i];
                mat[j][i]=temp;
            }
        }
        for(int i=0; i<n; i++){
            int j=0;
            int k=n-1;
            while(j<k){
                int temp=mat[i][j];
                mat[i][j]=mat[i][k];
                mat[i][k]=temp;
                j++;
                k--;
            }
            
        }
        
    }
};
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        for(int k=0; k<queries.size(); k++){
            int row1=queries[k][0];
            int col1=queries[k][1];

            int row2=queries[k][2];
            int col2=queries[k][3];

            for(int i=row1; i<=row2; i++){
                mat[i][col1]+=1;
                if(col2+1<n){
                    mat[i][col2+1]-=1;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        return mat;
    }
};
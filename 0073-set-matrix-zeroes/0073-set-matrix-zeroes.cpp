class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rowIdx;
        unordered_set<int> colIdx;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    rowIdx.insert(i);
                    colIdx.insert(j);
                }
            }
        }
        for(auto &it:rowIdx){
            for(int j=0; j<m; j++){
                matrix[it][j]=0;
            }
        }
        for(auto &it:colIdx){
            for(int j=0; j<n; j++){
                matrix[j][it]=0;
            }
        }
        return;
    }
};
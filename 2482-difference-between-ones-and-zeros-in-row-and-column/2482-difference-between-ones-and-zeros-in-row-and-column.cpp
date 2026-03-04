class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<int> countOnesInRows(row,0);
        vector<int> countOnesInCols(col,0);
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                countOnesInCols[j]+=grid[i][j];
                countOnesInRows[i]+=grid[i][j];
            }
        }
        vector<vector<int>> ans(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans[i][j]=countOnesInCols[j]+countOnesInRows[i]-(col-countOnesInCols[j])-(row-countOnesInRows[i]);
            }
        }
        return ans;
    }
};
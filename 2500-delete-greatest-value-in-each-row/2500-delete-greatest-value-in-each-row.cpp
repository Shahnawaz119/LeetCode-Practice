class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for(int row=0; row<grid.size(); row++){
            sort(grid[row].rbegin(),grid[row].rend());
        }
        int result=0;
        int j=grid[0].size();
        for(int j=0; j<grid[0].size(); j++){
            int currMax=0;
            for(int i=0; i<grid.size(); i++){
                currMax=max(currMax,grid[i][j]);
            }
            result+=currMax;
        }
        return result;
    }
};
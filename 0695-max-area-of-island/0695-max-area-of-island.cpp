class Solution {
public:
    void DFS(vector<vector<int>> &grid,int i,int j,int r,int c,int &currArea){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0){
            return;
        }
        currArea++;
        grid[i][j]=0;
        DFS(grid,i,j+1,r,c,currArea);
        DFS(grid,i-1,j,r,c,currArea);
        DFS(grid,i,j-1,r,c,currArea);
        DFS(grid,i+1,j,r,c,currArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxArea=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int currArea=0;
                if(grid[i][j]==1){
                    DFS(grid,i,j,r,c,currArea);
                }
                maxArea=max(maxArea,currArea);
            }
        }
        return maxArea;
    }
};
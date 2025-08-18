class Solution {
public:
    void DFS(vector<vector<int>> &grid,int i,int j,int r,int c,int &currFish){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]==0){
            return;
        }
        currFish+=grid[i][j];
        grid[i][j]=0;
        DFS(grid,i,j+1,r,c,currFish);
        DFS(grid,i-1,j,r,c,currFish);
        DFS(grid,i,j-1,r,c,currFish);
        DFS(grid,i+1,j,r,c,currFish);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int r=grid.size();
        if(r==0){
            return 0;
        }
        int c=grid[0].size();
        int fish=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                int currFish=0;
                if(grid[i][j]>0){
                    DFS(grid,i,j,r,c,currFish);
                }
                fish=max(fish,currFish);
            }
        }
        return fish;
    }
};
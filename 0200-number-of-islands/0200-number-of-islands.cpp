class Solution {
public:
    void DFS(vector<vector<char>>&grid,int i,int j,int r,int c){
        if(i<0 || j<0 || i>=r || j>=c || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        DFS(grid,i,j+1,r,c);
        DFS(grid,i-1,j,r,c);
        DFS(grid,i,j-1,r,c);
        DFS(grid,i+1,j,r,c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='1'){
                    DFS(grid,i,j,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};
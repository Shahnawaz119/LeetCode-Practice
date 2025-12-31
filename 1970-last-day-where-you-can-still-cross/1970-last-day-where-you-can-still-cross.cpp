class Solution {
public:
    int COL;
    int ROW;
    bool DFS(vector<vector<int>>&grid,int i,int j){
        if(i<0 || i>=ROW || j<0 || j>=COL || grid[i][j]!=0){
            return false;
        }
        if(i==ROW-1){
            return true;
        }
        grid[i][j]=1;
        return DFS(grid,i,j+1) ||
               DFS(grid,i-1,j) ||
               DFS(grid,i,j-1) ||
               DFS(grid,i+1,j);
        
    }
    bool isCross(vector<vector<int>>&cells,int mid){
        vector<vector<int>> grid(ROW,vector<int>(COL,0));
        for(int i=0; i<=mid; i++){
            int x=cells[i][0]-1;
            int y=cells[i][1]-1;
            grid[x][y]=1;
        }

        for(int j=0; j<COL; j++){
            if(grid[0][j]==0 && DFS(grid,0,j)){
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW=row;
        COL=col;
        int result=0;
        int l=0;
        int r=cells.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isCross(cells,mid)){
                result=mid+1;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
};
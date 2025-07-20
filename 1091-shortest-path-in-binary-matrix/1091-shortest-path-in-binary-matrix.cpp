class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1 || grid[r-1][c-1]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        vector<int> dx={0,-1,-1,-1,0,1,1,1};
        vector<int> dy={1,1,0,-1,-1,-1,0,1};
        while(!q.empty()){
            pair<int,int> node=q.front();
            int i=node.first;
            int j=node.second;
            int distance=grid[i][j];
            q.pop();
            if(i==r-1 && j==c-1){
                return distance;
            }
            for(int k=0; k<8; k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && y>=0 && x<r && y<c && grid[x][y]==0){
                    q.push({x,y});
                    grid[x][y]=distance+1;
                }
            }
        }
        return -1;
    }
};
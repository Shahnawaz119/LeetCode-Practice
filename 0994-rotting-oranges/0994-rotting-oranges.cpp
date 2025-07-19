class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int fresh=0;
        int rotten=0;
        queue<pair<int,int>> q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1){
                    fresh++;
                }else if(grid[i][j]==2){
                    rotten++;
                    q.push({i,j});
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,-1,0,1};
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int k=0; k<size; k++){
                pair<int,int> node=q.front();
                int i=node.first;
                int j=node.second;
                q.pop();
                for(int z=0; z<4; z++){
                    int x=i+dx[z];
                    int y=j+dy[z];
                    if(x>=0 && y>=0 && x<r && y<c && grid[x][y]==1){
                        grid[x][y]=2;
                        q.push({x,y});
                        fresh--;
                        rotten++;
                    }
                }
            }
            if(!q.empty()){
                ans++;
            }
        }
        return fresh==0 ? ans : -1;
    }
};